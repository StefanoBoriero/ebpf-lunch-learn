TARGET = xdp_inspector
ARCH = $(shell uname -m | sed 's/x86_64/x86/' | sed 's/aarch64/arm64/')
NETWORK_INTERFACE ?= wlp2s0

BPF_OBJ = ${TARGET:=.bpf.o}

all: $(BPF_OBJ)
.PHONY: all

%.bpf.o: %.bpf.c vmlinux.h
	clang \
	    -target bpf \
        -D __TARGET_ARCH_$(ARCH) \
	    -Wall \
	    -O2 -g -o $@ -c $<
	llvm-strip -g $@

vmlinux.h:
	# Generates a vmlinux.h file that contains kernel constants and functions
	bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h

clean: detach unload
	- rm $(BPF_OBJ)

load:
	# Load the eBPF program in the kernel. At this point is not attached to any event
	sudo bpftool prog load $(BPF_OBJ) /sys/fs/bpf/$(TARGET)

unload:
	# Unload the eBPF program from the kernel
	sudo rm /sys/fs/bpf/$(TARGET)

list:
	sudo bpftool prog list

net_list:
	sudo bpftool net list

attach:
	# Attached the eBPF program to a network interface. wlp2s0 is specific to my machine,
	# you can find the network interfaces for your machine running 'ip link' command
	sudo bpftool net attach xdp name $(TARGET) dev $(NETWORK_INTERFACE)

detach:
	# Detaches the program from the network interface. Since only one program per interface
	# can be loaded, it doesn't require the program name as a parameter
	sudo bpftool net detach xdp dev wlp2s0

debug:
	# Open the trace pipe were all eBPF print statements are sent
	sudo cat /sys/kernel/debug/tracing/trace_pipe
