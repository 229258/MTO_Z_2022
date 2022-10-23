#include <stdio.h>
#include <string.h>


int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
	
	
		if((format_string[i] == '#') && (format_string[i+1] == 'k')) {
			
			i++;
			printf("%s",param);
			
			for (int j = 0; j < strlen(format_string); j++) {
				if ((format_string[j] >= 'A') && (format_string[j] <= 'Z'))
					format_string[j] += 32;
				else if ((format_string[j] >= 'a') && (format_string[j] <= 'z'))
					format_string[j] -= 32;

			}
					
			
		}else if((format_string[i] == '#') && (format_string[i+1] == '.')) {
			if ((isdigit(format_string[i+2]) != 0) && (format_string[i+3] == 'k')) {
				
				// terminator required because of protection for segmentation fault
				char value_with_terminator[2] = {format_string[i + 2], '\0'};
				int number_of_characters = atoi(value_with_terminator);
							
				i = i + 3;
				printf("%s",param);
				
				int j = 0;
				for (j = 0; j < strlen(format_string); j++) {
					if ((format_string[j] >= 'A') && (format_string[j] <= 'Z'))
						format_string[j] += 32;
					else if ((format_string[j] >= 'a') && (format_string[j] <= 'z'))
						format_string[j] -= 32;

				}
				//format_string[j] = '\n';
			}
		} else if((format_string[i] == '#') && (isdigit(format_string[i+1]) != 0) && (format_string[i+3] == 'k')) {
				// terminator required because of protection for segmentation fault
				char value_with_terminator[2] = {format_string[i + 1], '\0'};
				int number_of_characters = atoi(value_with_terminator);
							
				i = i + 2; 
				printf("%s",param);
				
				int j = 0;
				for (j = 0; j < strlen(format_string); j++) {
					if ((format_string[j] >= 'A') && (format_string[j] <= 'Z'))
						format_string[j] += 32;
					else if ((format_string[j] >= 'a') && (format_string[j] <= 'z'))
						format_string[j] -= 32;

				}
				//format_string[j] = '\n';
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
