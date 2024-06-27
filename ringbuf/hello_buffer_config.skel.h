/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __HELLO_BUFFER_CONFIG_BPF_SKEL_H__
#define __HELLO_BUFFER_CONFIG_BPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct hello_buffer_config_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *my_config;
		struct bpf_map *output_buffer;
		struct bpf_map *data;
		struct bpf_map *kconfig;
	} maps;
	struct {
		struct bpf_program *hello;
	} progs;
	struct {
		struct bpf_link *hello;
	} links;
	struct hello_buffer_config_bpf__data {
		char message[12];
	} *data;
	struct hello_buffer_config_bpf__kconfig {
		_Bool LINUX_HAS_SYSCALL_WRAPPER;
	} *kconfig;

#ifdef __cplusplus
	static inline struct hello_buffer_config_bpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct hello_buffer_config_bpf *open_and_load();
	static inline int load(struct hello_buffer_config_bpf *skel);
	static inline int attach(struct hello_buffer_config_bpf *skel);
	static inline void detach(struct hello_buffer_config_bpf *skel);
	static inline void destroy(struct hello_buffer_config_bpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
hello_buffer_config_bpf__destroy(struct hello_buffer_config_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
hello_buffer_config_bpf__create_skeleton(struct hello_buffer_config_bpf *obj);

static inline struct hello_buffer_config_bpf *
hello_buffer_config_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct hello_buffer_config_bpf *obj;
	int err;

	obj = (struct hello_buffer_config_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = hello_buffer_config_bpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	hello_buffer_config_bpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct hello_buffer_config_bpf *
hello_buffer_config_bpf__open(void)
{
	return hello_buffer_config_bpf__open_opts(NULL);
}

static inline int
hello_buffer_config_bpf__load(struct hello_buffer_config_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct hello_buffer_config_bpf *
hello_buffer_config_bpf__open_and_load(void)
{
	struct hello_buffer_config_bpf *obj;
	int err;

	obj = hello_buffer_config_bpf__open();
	if (!obj)
		return NULL;
	err = hello_buffer_config_bpf__load(obj);
	if (err) {
		hello_buffer_config_bpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
hello_buffer_config_bpf__attach(struct hello_buffer_config_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
hello_buffer_config_bpf__detach(struct hello_buffer_config_bpf *obj)
{
	bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *hello_buffer_config_bpf__elf_bytes(size_t *sz);

static inline int
hello_buffer_config_bpf__create_skeleton(struct hello_buffer_config_bpf *obj)
{
	struct bpf_object_skeleton *s;
	int err;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)	{
		err = -ENOMEM;
		goto err;
	}

	s->sz = sizeof(*s);
	s->name = "hello_buffer_config_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 4;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	s->maps[0].name = "my_config";
	s->maps[0].map = &obj->maps.my_config;

	s->maps[1].name = "output_buffer";
	s->maps[1].map = &obj->maps.output_buffer;

	s->maps[2].name = "hello_bu.data";
	s->maps[2].map = &obj->maps.data;
	s->maps[2].mmaped = (void **)&obj->data;

	s->maps[3].name = "hello_b.kconfig";
	s->maps[3].map = &obj->maps.kconfig;
	s->maps[3].mmaped = (void **)&obj->kconfig;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "hello";
	s->progs[0].prog = &obj->progs.hello;
	s->progs[0].link = &obj->links.hello;

	s->data = hello_buffer_config_bpf__elf_bytes(&s->data_sz);

	obj->skeleton = s;
	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return err;
}

static inline const void *hello_buffer_config_bpf__elf_bytes(size_t *sz)
{
	static const char data[] __attribute__((__aligned__(8))) = "\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xc8\x13\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0e\0\
\x01\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\x22\0\0\0\0\0\0\x15\x02\x47\0\0\
\0\0\0\xb7\x02\0\0\x70\0\0\0\x79\x13\x70\0\0\0\0\0\x0f\x23\0\0\0\0\0\0\xbf\xa1\
\0\0\0\0\0\0\x07\x01\0\0\xd0\xfe\xff\xff\xb7\x02\0\0\x08\0\0\0\x85\0\0\0\x71\0\
\0\0\x79\xa6\xd0\xfe\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\0\0\x7b\
\x1a\xf0\xff\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\x7b\x1a\xe0\xff\0\0\0\0\x7b\x1a\
\xd8\xff\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\x7b\x1a\xc8\xff\0\0\0\0\x7b\x1a\xc0\
\xff\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x7b\x1a\xb0\xff\0\0\0\0\x7b\x1a\xa8\xff\0\
\0\0\0\x7b\x1a\xa0\xff\0\0\0\0\x7b\x1a\x98\xff\0\0\0\0\x7b\x1a\x90\xff\0\0\0\0\
\x7b\x1a\x88\xff\0\0\0\0\x7b\x1a\x80\xff\0\0\0\0\x7b\x1a\x78\xff\0\0\0\0\x7b\
\x1a\x70\xff\0\0\0\0\x7b\x1a\x68\xff\0\0\0\0\x7b\x1a\x60\xff\0\0\0\0\x7b\x1a\
\x58\xff\0\0\0\0\x7b\x1a\x50\xff\0\0\0\0\x7b\x1a\x48\xff\0\0\0\0\x7b\x1a\x40\
\xff\0\0\0\0\x7b\x1a\x38\xff\0\0\0\0\x7b\x1a\x30\xff\0\0\0\0\x7b\x1a\x28\xff\0\
\0\0\0\x7b\x1a\x20\xff\0\0\0\0\x7b\x1a\x18\xff\0\0\0\0\x7b\x1a\x10\xff\0\0\0\0\
\x7b\x1a\x08\xff\0\0\0\0\x7b\x1a\0\xff\0\0\0\0\x7b\x1a\xf8\xfe\0\0\0\0\x7b\x1a\
\xf0\xfe\0\0\0\0\x7b\x1a\xe8\xfe\0\0\0\0\x7b\x1a\xe0\xfe\0\0\0\0\x7b\x1a\xd8\
\xfe\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x63\x0a\xd0\xfe\0\0\0\0\
\x85\0\0\0\x0f\0\0\0\x63\x0a\xd4\xfe\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\
\xd8\xfe\xff\xff\xb7\x02\0\0\x10\0\0\0\x85\0\0\0\x10\0\0\0\xbf\xa1\0\0\0\0\0\0\
\x07\x01\0\0\xf4\xfe\xff\xff\xb7\x02\0\0\x0a\x01\0\0\xbf\x63\0\0\0\0\0\0\x85\0\
\0\0\x72\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xd4\xfe\xff\xff\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xe8\
\xfe\xff\xff\x15\0\x41\0\0\0\0\0\xb7\x02\0\0\x0c\0\0\0\xbf\x03\0\0\0\0\0\0\x05\
\0\x41\0\0\0\0\0\x79\x16\x70\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\0\0\
\0\0\x7b\x1a\xf0\xff\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\x7b\x1a\xe0\xff\0\0\0\0\
\x7b\x1a\xd8\xff\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\x7b\x1a\xc8\xff\0\0\0\0\x7b\
\x1a\xc0\xff\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x7b\x1a\xb0\xff\0\0\0\0\x7b\x1a\
\xa8\xff\0\0\0\0\x7b\x1a\xa0\xff\0\0\0\0\x7b\x1a\x98\xff\0\0\0\0\x7b\x1a\x90\
\xff\0\0\0\0\x7b\x1a\x88\xff\0\0\0\0\x7b\x1a\x80\xff\0\0\0\0\x7b\x1a\x78\xff\0\
\0\0\0\x7b\x1a\x70\xff\0\0\0\0\x7b\x1a\x68\xff\0\0\0\0\x7b\x1a\x60\xff\0\0\0\0\
\x7b\x1a\x58\xff\0\0\0\0\x7b\x1a\x50\xff\0\0\0\0\x7b\x1a\x48\xff\0\0\0\0\x7b\
\x1a\x40\xff\0\0\0\0\x7b\x1a\x38\xff\0\0\0\0\x7b\x1a\x30\xff\0\0\0\0\x7b\x1a\
\x28\xff\0\0\0\0\x7b\x1a\x20\xff\0\0\0\0\x7b\x1a\x18\xff\0\0\0\0\x7b\x1a\x10\
\xff\0\0\0\0\x7b\x1a\x08\xff\0\0\0\0\x7b\x1a\0\xff\0\0\0\0\x7b\x1a\xf8\xfe\0\0\
\0\0\x7b\x1a\xf0\xfe\0\0\0\0\x7b\x1a\xe8\xfe\0\0\0\0\x7b\x1a\xe0\xfe\0\0\0\0\
\x7b\x1a\xd8\xfe\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x63\x0a\xd0\
\xfe\0\0\0\0\x85\0\0\0\x0f\0\0\0\x63\x0a\xd4\xfe\0\0\0\0\xbf\xa1\0\0\0\0\0\0\
\x07\x01\0\0\xd8\xfe\xff\xff\xb7\x02\0\0\x10\0\0\0\x85\0\0\0\x10\0\0\0\xbf\xa1\
\0\0\0\0\0\0\x07\x01\0\0\xf4\xfe\xff\xff\xb7\x02\0\0\x0a\x01\0\0\xbf\x63\0\0\0\
\0\0\0\x85\0\0\0\x72\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xd4\xfe\xff\xff\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\
\x01\0\0\xe8\xfe\xff\xff\x15\0\x01\0\0\0\0\0\x05\0\xbf\xff\0\0\0\0\xb7\x02\0\0\
\x0c\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x73\0\0\0\xbf\xa2\0\0\
\0\0\0\0\x07\x02\0\0\xd0\xfe\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\
\x03\0\0\x30\x01\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x82\0\0\0\xb7\0\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x48\x65\x6c\x6c\x6f\x20\x65\x42\x50\x46\0\0\x44\x75\x61\x6c\
\x20\x42\x53\x44\x2f\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9f\xeb\x01\
\0\x18\0\0\0\0\0\0\0\xb8\x03\0\0\xb8\x03\0\0\x07\x03\0\0\0\0\0\0\0\0\0\x02\x03\
\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\
\0\0\0\x04\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\
\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\0\x28\0\0\0\0\0\
\0\0\0\0\x02\x08\0\0\0\x19\0\0\0\0\0\0\x08\x09\0\0\0\x1d\0\0\0\0\0\0\x08\x0a\0\
\0\0\x23\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\0\x30\0\
\0\0\x01\0\0\x04\x0c\0\0\0\x3b\0\0\0\x0e\0\0\0\0\0\0\0\x43\0\0\0\0\0\0\x01\x01\
\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x04\0\0\0\x0c\0\0\0\0\0\
\0\0\x04\0\0\x04\x20\0\0\0\x48\0\0\0\x01\0\0\0\0\0\0\0\x4d\0\0\0\x05\0\0\0\x40\
\0\0\0\x59\0\0\0\x07\0\0\0\x80\0\0\0\x5d\0\0\0\x0b\0\0\0\xc0\0\0\0\x63\0\0\0\0\
\0\0\x0e\x0f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x12\0\0\0\0\0\0\0\0\0\0\x03\0\0\
\0\0\x02\0\0\0\x04\0\0\0\x1b\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\0\0\x04\0\0\0\0\0\x02\0\0\x04\x10\0\0\0\x48\0\
\0\0\x11\0\0\0\0\0\0\0\x4d\0\0\0\x13\0\0\0\x40\0\0\0\x6d\0\0\0\0\0\0\x0e\x15\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x18\0\0\0\x7b\0\0\0\x15\0\0\x04\xa8\0\0\0\x83\
\0\0\0\x19\0\0\0\0\0\0\0\x87\0\0\0\x19\0\0\0\x40\0\0\0\x8b\0\0\0\x19\0\0\0\x80\
\0\0\0\x8f\0\0\0\x19\0\0\0\xc0\0\0\0\x93\0\0\0\x19\0\0\0\0\x01\0\0\x96\0\0\0\
\x19\0\0\0\x40\x01\0\0\x99\0\0\0\x19\0\0\0\x80\x01\0\0\x9d\0\0\0\x19\0\0\0\xc0\
\x01\0\0\xa1\0\0\0\x19\0\0\0\0\x02\0\0\xa4\0\0\0\x19\0\0\0\x40\x02\0\0\xa7\0\0\
\0\x19\0\0\0\x80\x02\0\0\xaa\0\0\0\x19\0\0\0\xc0\x02\0\0\xad\0\0\0\x19\0\0\0\0\
\x03\0\0\xb0\0\0\0\x19\0\0\0\x40\x03\0\0\xb3\0\0\0\x19\0\0\0\x80\x03\0\0\xb6\0\
\0\0\x19\0\0\0\xc0\x03\0\0\xbe\0\0\0\x19\0\0\0\0\x04\0\0\xc1\0\0\0\x19\0\0\0\
\x40\x04\0\0\xc4\0\0\0\x19\0\0\0\x80\x04\0\0\xca\0\0\0\x19\0\0\0\xc0\x04\0\0\
\xcd\0\0\0\x19\0\0\0\0\x05\0\0\xd0\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\
\x01\0\0\x0d\x02\0\0\0\xde\0\0\0\x17\0\0\0\xe2\0\0\0\x01\0\0\x0c\x1a\0\0\0\x3b\
\0\0\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\xc2\x02\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\
\x04\xc8\x02\0\0\0\0\0\x0e\x1d\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\
\0\0\x04\0\0\0\x0d\0\0\0\xe2\x02\0\0\0\0\0\x0e\x1f\0\0\0\x01\0\0\0\xea\x02\0\0\
\x01\0\0\x0f\0\0\0\0\x1c\0\0\0\0\0\0\0\x0c\0\0\0\xf0\x02\0\0\x01\0\0\x0f\0\0\0\
\0\x1e\0\0\0\0\0\0\0\x01\0\0\0\xf9\x02\0\0\x02\0\0\x0f\0\0\0\0\x10\0\0\0\0\0\0\
\0\x20\0\0\0\x16\0\0\0\0\0\0\0\x10\0\0\0\xff\x02\0\0\x01\0\0\x0f\0\0\0\0\x20\0\
\0\0\0\0\0\0\x0d\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\
\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x75\x33\x32\0\x5f\x5f\x75\x33\x32\0\x75\
\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x75\x73\x65\x72\x5f\x6d\x73\x67\
\x5f\x74\0\x6d\x65\x73\x73\x61\x67\x65\0\x63\x68\x61\x72\0\x74\x79\x70\x65\0\
\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\
\x65\0\x6d\x79\x5f\x63\x6f\x6e\x66\x69\x67\0\x6f\x75\x74\x70\x75\x74\x5f\x62\
\x75\x66\x66\x65\x72\0\x70\x74\x5f\x72\x65\x67\x73\0\x72\x31\x35\0\x72\x31\x34\
\0\x72\x31\x33\0\x72\x31\x32\0\x62\x70\0\x62\x78\0\x72\x31\x31\0\x72\x31\x30\0\
\x72\x39\0\x72\x38\0\x61\x78\0\x63\x78\0\x64\x78\0\x73\x69\0\x64\x69\0\x6f\x72\
\x69\x67\x5f\x61\x78\0\x69\x70\0\x63\x73\0\x66\x6c\x61\x67\x73\0\x73\x70\0\x73\
\x73\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\0\x63\x74\x78\0\x68\
\x65\x6c\x6c\x6f\0\x6b\x73\x79\x73\x63\x61\x6c\x6c\x2f\x65\x78\x65\x63\x76\x65\
\0\x2f\x68\x6f\x6d\x65\x2f\x73\x74\x65\x66\x61\x6e\x6f\x2f\x44\x65\x76\x65\x6c\
\x6f\x70\x6d\x65\x6e\x74\x2f\x65\x62\x70\x66\x2d\x6c\x75\x6e\x63\x68\x2d\x6c\
\x65\x61\x72\x6e\x2f\x72\x69\x6e\x67\x62\x75\x66\x2f\x68\x65\x6c\x6c\x6f\x5f\
\x62\x75\x66\x66\x65\x72\x5f\x63\x6f\x6e\x66\x69\x67\x2e\x62\x70\x66\x2e\x63\0\
\x69\x6e\x74\x20\x42\x50\x46\x5f\x4b\x50\x52\x4f\x42\x45\x5f\x53\x59\x53\x43\
\x41\x4c\x4c\x28\x68\x65\x6c\x6c\x6f\x2c\x20\x63\x6f\x6e\x73\x74\x20\x63\x68\
\x61\x72\x20\x2a\x70\x61\x74\x68\x6e\x61\x6d\x65\x29\x20\x7b\0\x30\x3a\x31\x34\
\0\x20\x20\x73\x74\x72\x75\x63\x74\x20\x64\x61\x74\x61\x5f\x74\x20\x64\x61\x74\
\x61\x20\x3d\x20\x7b\x7d\x3b\0\x20\x20\x64\x61\x74\x61\x2e\x70\x69\x64\x20\x3d\
\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\
\x64\x5f\x74\x67\x69\x64\x28\x29\x20\x3e\x3e\x20\x33\x32\x3b\0\x20\x20\x64\x61\
\x74\x61\x2e\x75\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\
\x72\x72\x65\x6e\x74\x5f\x75\x69\x64\x5f\x67\x69\x64\x28\x29\x20\x26\x20\x30\
\x78\x46\x46\x46\x46\x46\x46\x46\x46\x3b\0\x20\x20\x62\x70\x66\x5f\x67\x65\x74\
\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x63\x6f\x6d\x6d\x28\x26\x64\x61\x74\x61\
\x2e\x63\x6f\x6d\x6d\x61\x6e\x64\x2c\x20\x73\x69\x7a\x65\x6f\x66\x28\x64\x61\
\x74\x61\x2e\x63\x6f\x6d\x6d\x61\x6e\x64\x29\x29\x3b\0\x20\x20\x62\x70\x66\x5f\
\x70\x72\x6f\x62\x65\x5f\x72\x65\x61\x64\x5f\x75\x73\x65\x72\x5f\x73\x74\x72\
\x28\x26\x64\x61\x74\x61\x2e\x70\x61\x74\x68\x2c\x20\x73\x69\x7a\x65\x6f\x66\
\x28\x64\x61\x74\x61\x2e\x70\x61\x74\x68\x29\x2c\x20\x70\x61\x74\x68\x6e\x61\
\x6d\x65\x29\x3b\0\x20\x20\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\
\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x6d\x79\x5f\x63\x6f\x6e\x66\
\x69\x67\x2c\x20\x26\x64\x61\x74\x61\x2e\x75\x69\x64\x29\x3b\0\x20\x20\x69\x66\
\x20\x28\x70\x20\x21\x3d\x20\x30\x29\x20\x7b\0\x5f\x42\x6f\x6f\x6c\0\x4c\x49\
\x4e\x55\x58\x5f\x48\x41\x53\x5f\x53\x59\x53\x43\x41\x4c\x4c\x5f\x57\x52\x41\
\x50\x50\x45\x52\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2e\x64\x61\x74\x61\0\x2e\x6b\
\x63\x6f\x6e\x66\x69\x67\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\
\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x3c\x02\0\0\x50\x02\0\0\
\x3c\0\0\0\x08\0\0\0\xe8\0\0\0\x01\0\0\0\0\0\0\0\x1b\0\0\0\x10\0\0\0\xe8\0\0\0\
\x23\0\0\0\0\0\0\0\xf8\0\0\0\x45\x01\0\0\x05\x68\0\0\x48\0\0\0\xf8\0\0\0\x45\
\x01\0\0\x05\x68\0\0\x58\0\0\0\xf8\0\0\0\x45\x01\0\0\x05\x68\0\0\x68\0\0\0\xf8\
\0\0\0\x80\x01\0\0\x11\x6c\0\0\x90\x01\0\0\xf8\0\0\0\x9b\x01\0\0\x0e\x78\0\0\
\x98\x01\0\0\xf8\0\0\0\x9b\x01\0\0\x29\x78\0\0\xa0\x01\0\0\xf8\0\0\0\x9b\x01\0\
\0\x0c\x78\0\0\xa8\x01\0\0\xf8\0\0\0\xca\x01\0\0\x0e\x7c\0\0\xb0\x01\0\0\xf8\0\
\0\0\xca\x01\0\0\x0c\x7c\0\0\xb8\x01\0\0\xf8\0\0\0\x80\x01\0\0\x11\x6c\0\0\xc8\
\x01\0\0\xf8\0\0\0\xff\x01\0\0\x03\x84\0\0\xd8\x01\0\0\xf8\0\0\0\x3c\x02\0\0\
\x1b\x88\0\0\xe8\x01\0\0\xf8\0\0\0\x3c\x02\0\0\x03\x88\0\0\0\x02\0\0\xf8\0\0\0\
\xca\x01\0\0\x08\x7c\0\0\x10\x02\0\0\xf8\0\0\0\x80\x02\0\0\x07\x90\0\0\x28\x02\
\0\0\xf8\0\0\0\x80\x01\0\0\x11\x6c\0\0\x38\x02\0\0\xf8\0\0\0\xb2\x02\0\0\x07\
\x94\0\0\x40\x02\0\0\xf8\0\0\0\0\0\0\0\0\0\0\0\x58\x02\0\0\xf8\0\0\0\x45\x01\0\
\0\x05\x68\0\0\x68\x02\0\0\xf8\0\0\0\x80\x01\0\0\x11\x6c\0\0\x90\x03\0\0\xf8\0\
\0\0\x9b\x01\0\0\x0e\x78\0\0\x98\x03\0\0\xf8\0\0\0\x9b\x01\0\0\x29\x78\0\0\xa0\
\x03\0\0\xf8\0\0\0\x9b\x01\0\0\x0c\x78\0\0\xa8\x03\0\0\xf8\0\0\0\xca\x01\0\0\
\x0e\x7c\0\0\xb0\x03\0\0\xf8\0\0\0\xca\x01\0\0\x0c\x7c\0\0\xb8\x03\0\0\xf8\0\0\
\0\x80\x01\0\0\x11\x6c\0\0\xc8\x03\0\0\xf8\0\0\0\xff\x01\0\0\x03\x84\0\0\xd8\
\x03\0\0\xf8\0\0\0\x3c\x02\0\0\x1b\x88\0\0\xe8\x03\0\0\xf8\0\0\0\x3c\x02\0\0\
\x03\x88\0\0\0\x04\0\0\xf8\0\0\0\xca\x01\0\0\x08\x7c\0\0\x10\x04\0\0\xf8\0\0\0\
\x80\x02\0\0\x07\x90\0\0\x28\x04\0\0\xf8\0\0\0\x80\x01\0\0\x11\x6c\0\0\x38\x04\
\0\0\xf8\0\0\0\xb2\x02\0\0\x07\x94\0\0\x48\x04\0\0\xf8\0\0\0\0\0\0\0\0\0\0\0\
\xa0\x04\0\0\xf8\0\0\0\x45\x01\0\0\x05\x68\0\0\x10\0\0\0\xe8\0\0\0\x03\0\0\0\
\x20\0\0\0\x18\0\0\0\x7b\x01\0\0\0\0\0\0\x28\0\0\0\x18\0\0\0\x7b\x01\0\0\0\0\0\
\0\x58\x02\0\0\x18\0\0\0\x7b\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb9\
\0\0\0\0\0\x03\0\x58\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb2\0\0\0\0\0\x03\0\x48\
\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\x03\0\x40\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\xab\0\0\0\0\0\x03\0\x60\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\0\0\0\
\x12\0\x03\0\0\0\0\0\0\0\0\0\xb0\x04\0\0\0\0\0\0\x80\0\0\0\x10\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x3c\0\0\0\x11\0\x07\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\
\x62\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x0c\0\0\0\0\0\0\0\x1a\0\0\0\x11\0\x07\0\
\x20\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa3\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x0d\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x10\x02\0\0\0\0\0\0\x01\0\0\
\0\x08\0\0\0\x10\x04\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x50\x04\0\0\0\0\0\0\x01\0\
\0\0\x09\0\0\0\x78\x04\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x74\x03\0\0\0\0\0\0\x04\
\0\0\0\x09\0\0\0\x8c\x03\0\0\0\0\0\0\x03\0\0\0\x07\0\0\0\xa4\x03\0\0\0\0\0\0\
\x04\0\0\0\x08\0\0\0\xb0\x03\0\0\0\0\0\0\x04\0\0\0\x0a\0\0\0\xc8\x03\0\0\0\0\0\
\0\x04\0\0\0\x0b\0\0\0\x2c\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x40\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x50\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x70\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x80\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x90\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xa0\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\xb0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xc0\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\xd0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xe0\0\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\xf0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\0\x01\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x10\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x20\x01\0\0\0\0\0\
\0\x04\0\0\0\x01\0\0\0\x30\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x40\x01\0\0\0\0\
\0\0\x04\0\0\0\x01\0\0\0\x50\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\x01\0\0\0\
\0\0\0\x04\0\0\0\x01\0\0\0\x70\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x80\x01\0\0\
\0\0\0\0\x04\0\0\0\x01\0\0\0\x90\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xa0\x01\0\
\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xb0\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xc0\x01\
\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xd0\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xe0\
\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xf0\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\0\
\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x10\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\
\x20\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x30\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\
\0\x40\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x50\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\
\0\0\x60\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x7c\x02\0\0\0\0\0\0\x04\0\0\0\x01\
\0\0\0\x8c\x02\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x9c\x02\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x0f\x12\x14\x11\x13\0\x2e\x74\x65\x78\x74\0\x2e\x72\x65\x6c\x2e\x42\
\x54\x46\x2e\x65\x78\x74\0\x2e\x6d\x61\x70\x73\0\x6f\x75\x74\x70\x75\x74\x5f\
\x62\x75\x66\x66\x65\x72\0\x68\x65\x6c\x6c\x6f\0\x2e\x6c\x6c\x76\x6d\x5f\x61\
\x64\x64\x72\x73\x69\x67\0\x6d\x79\x5f\x63\x6f\x6e\x66\x69\x67\0\x2e\x72\x65\
\x6c\x6b\x73\x79\x73\x63\x61\x6c\x6c\x2f\x65\x78\x65\x63\x76\x65\0\x6c\x69\x63\
\x65\x6e\x73\x65\0\x6d\x65\x73\x73\x61\x67\x65\0\x2e\x73\x74\x72\x74\x61\x62\0\
\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x64\x61\x74\x61\0\x4c\x49\x4e\x55\x58\x5f\
\x48\x41\x53\x5f\x53\x59\x53\x43\x41\x4c\x4c\x5f\x57\x52\x41\x50\x50\x45\x52\0\
\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\
\x30\x5f\x36\0\x4c\x42\x42\x30\x5f\x35\0\x4c\x42\x42\x30\x5f\x33\0\x4c\x42\x42\
\x30\x5f\x32\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6a\0\
\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xfd\x12\0\0\0\0\0\0\xc7\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\
\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4a\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xb0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xe8\x0f\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x0d\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x7a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\
\x04\0\0\0\0\0\0\x0c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x5a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xfc\x04\0\0\0\0\0\
\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x14\0\0\
\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x05\0\0\0\0\0\0\x30\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9e\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x05\0\0\0\0\0\0\xd7\x06\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9a\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x38\x10\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x0d\0\0\0\x08\0\0\0\
\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x18\x0c\0\0\0\0\0\0\xac\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x07\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x88\x10\0\0\0\0\0\0\x70\x02\0\0\0\0\0\0\x0d\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x2e\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\
\xf8\x12\0\0\0\0\0\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x72\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc8\x0e\0\0\0\0\
\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\
\0";

	*sz = sizeof(data) - 1;
	return (const void *)data;
}

#ifdef __cplusplus
struct hello_buffer_config_bpf *hello_buffer_config_bpf::open(const struct bpf_object_open_opts *opts) { return hello_buffer_config_bpf__open_opts(opts); }
struct hello_buffer_config_bpf *hello_buffer_config_bpf::open_and_load() { return hello_buffer_config_bpf__open_and_load(); }
int hello_buffer_config_bpf::load(struct hello_buffer_config_bpf *skel) { return hello_buffer_config_bpf__load(skel); }
int hello_buffer_config_bpf::attach(struct hello_buffer_config_bpf *skel) { return hello_buffer_config_bpf__attach(skel); }
void hello_buffer_config_bpf::detach(struct hello_buffer_config_bpf *skel) { hello_buffer_config_bpf__detach(skel); }
void hello_buffer_config_bpf::destroy(struct hello_buffer_config_bpf *skel) { hello_buffer_config_bpf__destroy(skel); }
const void *hello_buffer_config_bpf::elf_bytes(size_t *sz) { return hello_buffer_config_bpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
hello_buffer_config_bpf__assert(struct hello_buffer_config_bpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
	_Static_assert(sizeof(s->data->message) == 12, "unexpected size of 'message'");
	_Static_assert(sizeof(s->kconfig->LINUX_HAS_SYSCALL_WRAPPER) == 1, "unexpected size of 'LINUX_HAS_SYSCALL_WRAPPER'");
#ifdef __cplusplus
#undef _Static_assert
#endif
}

#endif /* __HELLO_BUFFER_CONFIG_BPF_SKEL_H__ */
