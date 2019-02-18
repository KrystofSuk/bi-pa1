
#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TEmployee
{
  struct TEmployee         * m_Next;
  struct TEmployee         * m_Bak;
  char                     * m_Name;
} TEMPLOYEE;

#endif /* __PROGTEST__ */
TEMPLOYEE * newEmployee2  (char * name, TEMPLOYEE * next )
{
  TEMPLOYEE * firstEmployee = (TEMPLOYEE * )malloc(sizeof(*firstEmployee));
  firstEmployee->m_Name = (char * )malloc(100*sizeof(char));
  strncpy(firstEmployee->m_Name, name, 100);
  firstEmployee->m_Next = next;
  free(name);
  firstEmployee->m_Bak=NULL;
  return firstEmployee;
}
TEMPLOYEE * newEmployee  ( const char * name, TEMPLOYEE * next )
{
  TEMPLOYEE * firstEmployee = (TEMPLOYEE * )malloc(sizeof(*firstEmployee));
  firstEmployee->m_Name = (char * )malloc(100*sizeof(char));
  strncpy(firstEmployee->m_Name, name, 100);
  firstEmployee->m_Next = next;
  firstEmployee->m_Bak=NULL;
  return firstEmployee;
}

TEMPLOYEE * reverseList(TEMPLOYEE * src){
  TEMPLOYEE * current = src;
  TEMPLOYEE * currentDEL = src;
  TEMPLOYEE * last = NULL; 
  while(current -> m_Next != NULL && current -> m_Next != src){
    last = newEmployee2(current -> m_Name, last);
    current = current -> m_Next;
    free(currentDEL);
    currentDEL = current;
  }
  last = newEmployee2(current -> m_Name, last);
  return last;
} 

TEMPLOYEE * cloneList ( TEMPLOYEE * src )
{
  if(src!=NULL){
    TEMPLOYEE * current = src;
    TEMPLOYEE * last = NULL; 
    while(current -> m_Next != NULL && current -> m_Next != src){
      last = newEmployee(current -> m_Name, last);
      current = current -> m_Next;
    }
    last = newEmployee(current -> m_Name, last);
    last = reverseList(last);
    TEMPLOYEE * currentNew = last; 
    current = src;
    while(current -> m_Next != NULL && current -> m_Next != src){
      if(current -> m_Bak != NULL){
        TEMPLOYEE * currentNewBAK = last; 
        TEMPLOYEE * currentBAK = src;
        while(currentBAK != current -> m_Bak){
          currentNewBAK = currentNewBAK -> m_Next;
          currentBAK = currentBAK -> m_Next;
        }
        currentNew -> m_Bak = currentNewBAK;
      }
      currentNew = currentNew -> m_Next;
      current = current -> m_Next;
    }
    if(current -> m_Bak != NULL){
      if(current -> m_Bak != NULL){
        TEMPLOYEE * currentNewBAK = last; 
        TEMPLOYEE * currentBAK = src;
        while(currentBAK != current -> m_Bak){
          currentNewBAK = currentNewBAK -> m_Next;
          currentBAK = currentBAK -> m_Next;
        }
        currentNew -> m_Bak = currentNewBAK;
      }
    }
    
    return last;
  }
  return NULL;
}

void freeList ( TEMPLOYEE * src )
{
  if(src!=NULL){
    TEMPLOYEE * now = src;
    while(now -> m_Next != NULL){
      TEMPLOYEE * next = now -> m_Next;
      free(now->m_Name);
      free(now);
      now = next;
    }  
  }
  return;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TEMPLOYEE * a, * b;
  char tmp[100];

  assert ( sizeof ( TEMPLOYEE ) == 3 * sizeof ( void * ) );
  a = NULL;
  b=cloneList(a);
  a = newEmployee ( "Peter", a );
  a = newEmployee ( "John", a );
  a = newEmployee ( "Joe", a );
  a = newEmployee ( "Maria", a );
  a -> m_Bak = a -> m_Next;
  a -> m_Next -> m_Next -> m_Bak = a -> m_Next -> m_Next -> m_Next;
  a -> m_Next -> m_Next -> m_Next -> m_Bak = a -> m_Next;
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Bak == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next );
  
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  b = cloneList ( a );
  strncpy ( tmp, "Moe", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
  strncpy ( tmp, "Victoria", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
  strncpy ( tmp, "Peter", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
/*
  printf("%s", b->m_Name);
  printf("%s", b-> m_Next -> m_Name);
  printf("%s", b-> m_Next-> m_Next -> m_Name);
  printf("%s", b-> m_Next-> m_Next-> m_Next -> m_Name);
*/
  b -> m_Next -> m_Next -> m_Next -> m_Bak = b -> m_Next -> m_Next; 

  assert ( a
           && ! strcmp ( a -> m_Name, "Peter" )
           && a -> m_Bak == NULL );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Victoria" )
           && a -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "Moe" )
           && a -> m_Next -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Maria" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Bak == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Bak == NULL );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  
  freeList ( a );
  b -> m_Next -> m_Bak = b -> m_Next;
  a = cloneList ( b );
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Bak == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Bak == a -> m_Next );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Bak == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Bak == b -> m_Next );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  
  freeList ( b );
  freeList ( a );
  return 0;
}
#endif /* __PROGTEST__ */
