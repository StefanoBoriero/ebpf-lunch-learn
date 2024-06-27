# eBPF for networking

This is just a toy example to showcase how to attach an eBPF program to a network interface.

## Instructions

- Run `make` to build the program.
- Run `make load` to load the program into the kernel.
- Run `make attach` to attach the program to the network interface. If it fails, check the network interface for your machine and pass it as a variable `make attach NETWORK_INTERFACE=your_interface`
- Run `make debug` to inspect output logs
