/*
 * Copyright (c) 2010 Przemo Nowaczyk <pnowaczyk.mail@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <sys/types.h>
#include "itoa.h"

static void	reverse(char *, size_t);

size_t sltoa(char *s, long int n) {
	size_t i = 0;
	long int sign_mask;
	unsigned long int nn;

	sign_mask = n >> sizeof(long int) * 8 - 1;
	nn = (n + sign_mask) ^ sign_mask;
	do {
		s[i++] = nn % 10 + '0';
	} while (nn /= 10);

	s[i] = '-';
	i += sign_mask & 1;
	s[i] = '\0';

	reverse(s, i);
	return (i);
}

size_t ultoa(char *s, unsigned long int n) {
	size_t i = 0;

	do {
		s[i++] = n % 10 + '0';
	} while (n /= 10);
	s[i] = '\0';

	reverse(s, i);
	return (i);
}

static void reverse(char *s, size_t s_len) {
	size_t i, j;
	char swap;

	for (i = 0, j = s_len - 1; i < j; ++i, --j) {
		swap = s[i];
		s[i] = s[j];
		s[j] = swap;
	}
}
