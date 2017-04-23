/*
 * Simple argv style field parser implementation
 *
 * Copyright (C) Johan Malm 2017
 *
 *   - argv[0] points to the beginning of the buffer
 *   - argv[1..MAX_FIELDS] point to each 'delim' separated field
 */

#ifndef ARGV_BUF_H
#define ARGV_BUF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS (16)

struct argv_buf {
	int argc;
	char *argv[MAX_FIELDS];
	char delim;
};

void argv_init(struct argv_buf *buf);
void argv_set_delim(struct argv_buf *buf, char delim);
void argv_strdup(struct argv_buf *buf, const char *s);
void argv_parse(struct argv_buf *buf);
void argv_free(struct argv_buf *buf);

#endif /* ARGV_BUF_H */