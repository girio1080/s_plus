#include <stdio.h>
#include <handy.h>

int main() {
  FILE *fp;
  char *fname = "test.txt";
  int i, j;
  int ch;
  int array[32][32];

  fp = fopen(fname, "r");
  if(fp == NULL){
    printf("ファイルが開けませんでした。\n");
    return 1;
  } else {
    printf("ファイルを開きました。\n");
  }

  
  for(i = 0; i < 32; i++) {
    for(j = 0; j < 32; j++) {
      ch = fgetc(fp);
      if((ch < 'a') || (ch > 'z')) {
	array[i][j] = 1;
      } else {
	array[i][j] = 0;	
      }
    }
  }

  for(i = 0; i < 31; i++) {
    for(j = 0; j < 31; j++) {
      printf("%d", array[i][j]);
    }
    printf("\n");
  }
  
  HgOpen(620, 620);


  for(i = 0; i < 31; i++) {
    for(j = 0; j < 31; j++) {
      if(array[i][j] == 1) {
	HgSetFillColor(HG_BLACK);
	HgSetColor(HG_WHITE);
	HgBoxFill(j * 20, (30 - i) * 20, 20, 20, 0);
      } else {
	HgSetFillColor(HG_WHITE);
	HgSetColor(HG_WHITE);
	HgBoxFill(j * 20, (30 - i) * 20, 20, 20, 0);	
      }
    }
  }
  
  HgGetChar();
  HgClose();
  fclose(fp);
  printf("ファイルを閉じました。\n");
  
  return 0;
}
