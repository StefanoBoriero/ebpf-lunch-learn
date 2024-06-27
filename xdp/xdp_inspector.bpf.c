#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

u32 count = 0;

SEC("xdp")
int xdp_inspector(struct xdp_md *ctx) {
    count++;
    bpf_printk("Counted %d packets!", count);
    return XDP_PASS;
};

char LICENSE[] SEC("license") = "Dual BSD/GPL";
