#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <ctype.h>

void reverse(char *string) {
	int string_length = strlen(string);

	for (int i = 0; i < string_length / 2; ++i) {
		char temp = string[i];
		string[i] = string[string_length - i - 1];
		string[string_length - i - 1] = temp;
	}
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if ((format_string[i] == '#') && (format_string[i+1] == '.') && (isdigit(format_string[i + 2])) && (format_string[i+3] == 'g')) {
			i+=3;

			int j = 0;
			for (j = 0; j < strlen(param); ++j) {
				char c = param[j];
				if (isdigit(c)) {
					if (c == '0') {
						param[j] = '9';
					} else {

						param[j] = (((c - '0') * 9 + 1) % 10) + '0';
					}
				} else {
					param[j] = c;
				}
			}
			if (j < strlen(param)) {
				puts("");
				return -1;
			} else {
				printf("%s", param);
			}

		} else
			putchar(format_string[i]);

	}

	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
