/*
 * Copyright (c) 2011 Przemo Nowaczyk <pnowaczyk.mail@gmail.com>
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
#include <gtest/gtest.h>
#include "itoa.h"

TEST(ultoa_tests, handles_border_conditions) {
	char buff[32];

	EXPECT_EQ(1, ultoa(buff, 0));
	EXPECT_STREQ("0", buff);

	EXPECT_EQ(10, ultoa(buff, 4294967295u));
	EXPECT_STREQ("4294967295", buff);

	EXPECT_EQ(20, ultoa(buff, 18446744073709551615ul));
	EXPECT_STREQ("18446744073709551615", buff);
}

TEST(sltoa_tests, handles_negative_values) {
	char buff[32];

	EXPECT_EQ(2, sltoa(buff, -1));
	EXPECT_STREQ("-1", buff);

	EXPECT_EQ(11, sltoa(buff, -2147483648));
	EXPECT_STREQ("-2147483648", buff);

	EXPECT_EQ(20, sltoa(buff, -9223372036854775807l));
	EXPECT_STREQ("-9223372036854775807", buff);
}

TEST(sltoa_tests, handles_positive_values) {
	char buff[32];

	EXPECT_EQ(1, sltoa(buff, 0));
	EXPECT_STREQ("0", buff);

	EXPECT_EQ(10, sltoa(buff, 2147483647));
	EXPECT_STREQ("2147483647", buff);

	EXPECT_EQ(19, sltoa(buff, 9223372036854775807l));
	EXPECT_STREQ("9223372036854775807", buff);
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return (RUN_ALL_TESTS());
}
