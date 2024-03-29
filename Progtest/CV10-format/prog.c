#ifndef __PROGTEST__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */

char * allocateString(int size, int prevSize, char * res){
  char * tmp = (char *)malloc((size)*sizeof(char));    
  for(int t = 0; t < prevSize; t++){
    tmp[t] = res[t];    
  }
  free(res);
  return tmp;
}

char * wordWrap(int width, const char * src )
{
  char * res = NULL;
  int maxSize = 0;
  int inSpaces = 0;
  int odst = 0;
  while(src[maxSize] != '\0'){
    maxSize++;
  }
  res = allocateString(maxSize+1,0,res);
  
  int index = 0;
  int writeIndex = 0;
  int lastWordIndex = 0;
  int letterCount = 0;
  while(src[index] != '\0'){
    char c = src[index];
    if(c == ' ' || c == '\t'){
      inSpaces = 1;
    }else if(c == '\n'){
      odst++;
    }
    else{
      if(odst > 1){
        res[writeIndex] = '\n';
        writeIndex++;
        res[writeIndex] = '\n';
        writeIndex++;
        odst = 0;        
        lastWordIndex = writeIndex;
        letterCount = 0;
      }
      if(odst == 1){  
        if(inSpaces == 0){
          res[writeIndex] = ' ';
          letterCount++;
          writeIndex++;
          odst = 0;        
          lastWordIndex = writeIndex;
        }
        else{
          odst = 0;
        }
      }
      if(inSpaces){  
        if(letterCount != 0){      
          res[writeIndex] = ' ';
          letterCount++;
          writeIndex++;
          inSpaces = 0;        
          lastWordIndex = writeIndex;
        }else{
          inSpaces = 0;
        }
      }
      res[writeIndex] = src[index];
      letterCount++;
      writeIndex++;
      if(letterCount > width){
        if(writeIndex - lastWordIndex > width){
          free(res);
          return NULL;
        }
        res[lastWordIndex-1] = '\n';
        letterCount = writeIndex-lastWordIndex;
      }
    }
    index++;
  }
  res = allocateString(writeIndex+2,writeIndex,res);

  res[writeIndex] ='\n';
  res[writeIndex+1] ='\0';
  return res;
}

#ifndef __PROGTEST__
int                main                                     ( void )
{
  
  char * res;
  const char * s0 = 
    "Lorem ipsum dolor                   \t\t\t sit amet, consectetuer adipiscing elit. Integer metus\n"
    "pede, pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat\n"
    "orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus\n"
    "lectus, vitae feugiat purus orci ultricies turpis. Pellentesque habitant\n"
    "morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam\n"
    "in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor\n"
    "ultrices neque. Mauris semper, mauris ut feugiat ultricies, augue purus\n"
    "tincidunt  elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh dolor laoreet leo, sed pharetra pede\n"
    "libero non diam.";
  const char * s1 = 
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus\n"
    "pede, pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat\n"
    "orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus\n"
    "lectus, vitae feugiat purus orci ultricies turpis. Pellentesque habitant\n"
    "morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam\n"
    "in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor\n"
    "ultrices neque. Mauris semper, mauris ut feugiat ultricies, augue purus\n"
    "tincidunt  elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh\tdolor laoreet leo, sed pharetra pede\n"
    "libero non diam.\n"
    "\n"
    "Proin est nisi,                     gravida ac, vulputate id, fringilla sit\n"
    "amet, magna. Nam congue cursus magna. In malesuada, velit a gravida sodales,\n"
    "dolor nisl vestibulum orci, sit amet sagittis mauris tellus nec purus. Nulla\n"
    "eget risus. Quisque nec sapien blandit odio convallis ullamcorper. Lorem\n"
    "ipsum dolor sit amet, consectetuer adipiscing elit. Pellentesque cursus.\n"
    "Aliquam tempus neque vitae libero molestie ut auctor.\n"
    "\n"
    "\n"
    "\n"
    "In nec massa eu tortor vulputate suscipit.\tNam tristique magna nec pede. Sed\n"
    "a nisi. Nulla sed augue ut risus placerat porttitor. Ut aliquam. Nulla\n"
    "facilisi. Nulla vehicula nibh ac sapien. Nunc facilisis dapibus ipsum. Donec\n"
    "sed mauris. Nulla quam nisi, laoreet non, dignissim posuere, lacinia nec,\n"
    "turpis. Mauris malesuada nisi sed enim. In hac habitasse platea dictumst.\n"
    "Fusce    faucibus, turpis nec auctor posuere, nulla tellus scelerisque metus,\n"
    "quis molestie mi dui id quam. Mauris vestibulum. Nam ullamcorper.\n"
    "\n";
  res = wordWrap ( 40, s0 );
  assert ( ! strcmp ( res, 
    "Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin\n"
    "rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies\n"
    "turpis. Pellentesque habitant morbi\n"
    "tristique senectus et netus et malesuada\n"
    "fames ac turpis egestas. Nam in pede.\n"
    "Etiam eu sem id urna ultricies congue.\n"
    "Vestibulum porttitor ultrices neque.\n"
    "Mauris semper, mauris ut feugiat\n"
    "ultricies, augue purus tincidunt elit,\n"
    "eu interdum ante nisl ac ante.\n"
    "Pellentesque dui. Vestibulum pretium,\n"
    "augue non cursus pretium, nibh dolor\n"
    "laoreet leo, sed pharetra pede libero\n"
    "non diam.\n" ) );
  free ( res );

  res = wordWrap ( 120, s0 );
  assert ( ! strcmp ( res, 
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus pede, pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus lectus, vitae\n"
    "feugiat purus orci ultricies turpis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac\n"
    "turpis egestas. Nam in pede. Etiam eu sem id urna ultricies congue. Vestibulum porttitor ultrices neque. Mauris semper,\n"
    "mauris ut feugiat ultricies, augue purus tincidunt elit, eu interdum ante nisl ac ante. Pellentesque dui. Vestibulum\n"
    "pretium, augue non cursus pretium, nibh dolor laoreet leo, sed pharetra pede libero non diam.\n" ) );
  free ( res );

  res = wordWrap ( 10, s1 );
  assert ( res == NULL );
  free(res);

  res = wordWrap(50,"ffffffffffffffffffff ddddddddddddddddddddd\n"
"fdfdfdfdfdfdf                                          \t\t\t\t\t\t        ");
  printf("%s\n",res);
  assert(!strcmp(res, "ffffffffffffffffffff ddddddddddddddddddddd\n"
"fdfdfdfdfdfdf\n"));
free(res);

  res = wordWrap(50,"         abc          def         ghi        jkl   mno         pqr          stu\n");
  printf("%s\n",res);
  assert(!strcmp(res, "abc def ghi jkl mno pqr stu\n"));
free(res);

  res = wordWrap(50,"         abc          def         ghi        jkl   mno         pqr          stu           \n");
  printf("%s\n",res);
  assert(!strcmp(res, "abc def ghi jkl mno pqr stu\n"));
free(res);

  res = wordWrap(50,"abc    \n"
"    def   \n"
"    ghi   \n"
"   jkl \n"
" mno   \n"
"      pqr    \n"
"      stu\n");
  printf("%s\n",res);
  assert(!strcmp(res, "abc def ghi jkl mno pqr stu\n"));
free(res);

  res = wordWrap ( 40, s1 );
  assert ( ! strcmp ( res, 
    "Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit\n"
    "amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin\n"
    "rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies\n"
    "turpis. Pellentesque habitant morbi\n"
    "tristique senectus et netus et malesuada\n"
    "fames ac turpis egestas. Nam in pede.\n"
    "Etiam eu sem id urna ultricies congue.\n"
    "Vestibulum porttitor ultrices neque.\n"
    "Mauris semper, mauris ut feugiat\n"
    "ultricies, augue purus tincidunt elit,\n"
    "eu interdum ante nisl ac ante.\n"
    "Pellentesque dui. Vestibulum pretium,\n"
    "augue non cursus pretium, nibh dolor\n"
    "laoreet leo, sed pharetra pede libero\n"
    "non diam.\n"
    "\n"
    "Proin est nisi, gravida ac, vulputate\n"
    "id, fringilla sit amet, magna. Nam\n"
    "congue cursus magna. In malesuada, velit\n"
    "a gravida sodales, dolor nisl vestibulum\n"
    "orci, sit amet sagittis mauris tellus\n"
    "nec purus. Nulla eget risus. Quisque nec\n"
    "sapien blandit odio convallis\n"
    "ullamcorper. Lorem ipsum dolor sit amet,\n"
    "consectetuer adipiscing elit.\n"
    "Pellentesque cursus. Aliquam tempus\n"
    "neque vitae libero molestie ut auctor.\n"
    "\n"
    "In nec massa eu tortor vulputate\n"
    "suscipit. Nam tristique magna nec pede.\n"
    "Sed a nisi. Nulla sed augue ut risus\n"
    "placerat porttitor. Ut aliquam. Nulla\n"
    "facilisi. Nulla vehicula nibh ac sapien.\n"
    "Nunc facilisis dapibus ipsum. Donec sed\n"
    "mauris. Nulla quam nisi, laoreet non,\n"
    "dignissim posuere, lacinia nec, turpis.\n"
    "Mauris malesuada nisi sed enim. In hac\n"
    "habitasse platea dictumst. Fusce\n"
    "faucibus, turpis nec auctor posuere,\n"
    "nulla tellus scelerisque metus, quis\n"
    "molestie mi dui id quam. Mauris\n"
    "vestibulum. Nam ullamcorper.\n" ) );
  free ( res );

  res = wordWrap ( 80, s1 );
  assert ( ! strcmp ( res, 
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Integer metus pede,\n"
    "pretium vitae, rhoncus et, auctor sit amet, ligula. Integer volutpat orci et\n"
    "elit. Nunc tempus, urna at sollicitudin rutrum, arcu libero rhoncus lectus,\n"
    "vitae feugiat purus orci ultricies turpis. Pellentesque habitant morbi tristique\n"
    "senectus et netus et malesuada fames ac turpis egestas. Nam in pede. Etiam eu\n"
    "sem id urna ultricies congue. Vestibulum porttitor ultrices neque. Mauris\n"
    "semper, mauris ut feugiat ultricies, augue purus tincidunt elit, eu interdum\n"
    "ante nisl ac ante. Pellentesque dui. Vestibulum pretium, augue non cursus\n"
    "pretium, nibh dolor laoreet leo, sed pharetra pede libero non diam.\n"
    "\n"
    "Proin est nisi, gravida ac, vulputate id, fringilla sit amet, magna. Nam congue\n"
    "cursus magna. In malesuada, velit a gravida sodales, dolor nisl vestibulum orci,\n"
    "sit amet sagittis mauris tellus nec purus. Nulla eget risus. Quisque nec sapien\n"
    "blandit odio convallis ullamcorper. Lorem ipsum dolor sit amet, consectetuer\n"
    "adipiscing elit. Pellentesque cursus. Aliquam tempus neque vitae libero molestie\n"
    "ut auctor.\n"
    "\n"
    "In nec massa eu tortor vulputate suscipit. Nam tristique magna nec pede. Sed a\n"
    "nisi. Nulla sed augue ut risus placerat porttitor. Ut aliquam. Nulla facilisi.\n"
    "Nulla vehicula nibh ac sapien. Nunc facilisis dapibus ipsum. Donec sed mauris.\n"
    "Nulla quam nisi, laoreet non, dignissim posuere, lacinia nec, turpis. Mauris\n"
    "malesuada nisi sed enim. In hac habitasse platea dictumst. Fusce faucibus,\n"
    "turpis nec auctor posuere, nulla tellus scelerisque metus, quis molestie mi dui\n"
    "id quam. Mauris vestibulum. Nam ullamcorper.\n" ) );
  free ( res );

  return 0;
}
#endif /* __PROGTEST__ */
