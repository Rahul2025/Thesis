#include <stdio.h>
#include <string.h>

// IO Structures
const int i_size = 512, o_size = 51200;
int i_offset, i_max, o_offset;
char ibuffer[ 512 ], obuffer[ 51200 ];
FILE *in, *out;

char read_char(){
	//return getc(in);
	if( ! ( i_offset ^ i_max ) ){
		i_max = fread( ibuffer, sizeof(char), i_size, in );
		i_offset = 0;
	}
	return ibuffer[ i_offset++ ];
}

int read_int(){
	char t = read_char();
	while( t < 48 ) t = read_char();
	
	int N = t-48;
	t = read_char();
	while( t > 47 ){
		N = N*10 + t - 48;
		t = read_char();
	}
	
	return N;
}

void flush(){
	fwrite( obuffer, sizeof(char), o_offset, out );
	o_offset = 0;
}

void write_char(char ch){
	if( ! ( o_offset ^ o_size ) )
		flush();
	obuffer[o_offset++] = ch;
}

void write_int(int v, char ch){
	if( o_offset + 5 > o_size ) flush();
	if (v < 100000) {
		if (v < 1000) {
			if (v < 10) {
				obuffer[o_offset + 0] = v + 48;
				o_offset += 1;
			} else if (v < 100) {
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 2;
			} else {
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 3;
			}
		} else {
			if (v < 10000) {
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 4;
			} else {
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 5;
			}
		}
	} else {
		if (v < 100000000) {
			if (v < 1000000) {
				obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 6;
			} else if (v < 10000000) {
				obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 7;
			} else {
				obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 8;
			}
		} else {
			if (v < 1000000000) {
				obuffer[o_offset + 8] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 9;
			} else {
				obuffer[o_offset + 9] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 8] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 7] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 6] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 5] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 4] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 3] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 2] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 1] = v - v / 10 * 10 + 48; v /= 10;
				obuffer[o_offset + 0] = v + 48;
				o_offset += 10;
			}
		}
	}
	if(ch) obuffer[o_offset++] = ch;
}

#define MOD 10000009
#define SIZE 1000002

int main( int argc, char **argv ){
	int TC, N, M, i, j, R;
	char inp[ SIZE ];
	in = stdin; out = stdout;
	
	scanf( "%d\n", &TC );
	
	while( TC-- ){
		gets( inp );
		N = strlen( inp );
		
		M = ( N + 1 ) >> 1;
		
		for( i = 0, R = 1; i ^ M; i++ ){
			if( inp[ i ] == '?' && inp[ N - i - 1 ] == '?' )
				R *= 26;
			else if( inp[ i ] != '?' && inp[ N - i - 1 ] != '?' && inp[ i ] != inp[ N - i - 1 ] ){
				R = 0;
				break;
			}
			R %= MOD;
		}
	
		write_int( R , '\n' );
	}
	
	flush();
	return 0;
}