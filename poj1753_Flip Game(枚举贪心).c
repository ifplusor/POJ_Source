#include <stdio.h>

int count[16] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4
};

int mode[16] = {
	0x0,0x3,0x7,0x4,0xe,0xd,0x9,0xa,
	0xc,0xf,0xb,0x8,0x2,0x1,0x5,0x6
};

int h[4];
int v[4];

int flip(int b0, int b1, int b2, int b3) {
	int c = 0;
	c += count[b0];
	b1 ^= mode[b0];
	b2 ^= b0;
	c += count[b1];
	b2 ^= mode[b1];
	b3 ^= b1;
	c += count[b2];
	b3 ^= mode[b2];
	if (b3 == 0) {
		return c;
	} else {
		return 17;
	}
}

int main() {
	char color[10];
	int i, j;
	int t1, t2;

	v[0] = v[1] = v[2] = v[3] = 0;
	for(i = 0; i < 4; ++i) {
		scanf("%s", color);
		h[i] = 0;
		for (j = 0; j < 4; ++j) {
			h[i] <<= 1;
			v[j] <<= 1;
			if (color[j] == 'w') {
				h[i] += 1;
				v[j] += 1;
			}
		}
	}
	t1 = 17;
	// 枚举水平扫描
	for (i = 0; i < 16; i++) {
		t2 = count[i] + flip(h[0]^mode[i], h[1]^i, h[2], h[3]);
		if (t2 < t1) {
			t1 = t2;
		}
	}
	// 枚举垂直扫描
	for (i = 0; i < 16; i++) {
		t2 = count[i] + flip(v[0]^mode[i], v[1]^i, v[2], v[3]);
		if (t2 < t1) {
			t1 = t2;
		}
	}
	// 枚举水平翻转扫描
	for (i = 0; i < 16; i++) {
		t2 = count[i] + flip(h[0]^mode[i]^0xf, h[1]^i^0xf, h[2]^0xf, h[3]^0xf);
		if (t2 < t1) {
			t1 = t2;
		}
	}
	// 枚举垂直翻转扫描
	for (i = 0; i < 16; i++) {
		t2 = count[i] + flip(v[0]^mode[i]^0xf, v[1]^i^0xf, v[2]^0xf, v[3]^0xf);
		if (t2 < t1) {
			t1 = t2;
		}
	}
	if (t1 > 16) {
		printf("Impossible\n");
	} else {
		printf("%d\n", t1);
	}

	return 0;
}

