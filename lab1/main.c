#include <stdio.h>
#include <string.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;
			
			for (int j = 0; j < strlen(param); j++) {
				if (param[j] >= 'A' && param[j] <= 'Z')
					param[j] += 32;
				else if (param[j] >= 'a' && param[j] <= 'z')
					param[j] -= 32;
				
				
			}
		
			printf("%s",param);
		}else {
			
			putchar(format_string[i]);
		}
	}
	puts("");
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
