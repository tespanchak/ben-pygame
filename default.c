

#include <stdio.h>
#include <stdlib.h>
#define For_List(list) for(Trem* trem = list->start_trem;trem!=NULL;trem=trem->next)
//struct
//typedef
//define
typedef struct List List;
typedef struct Trem Trem;
void _List_append(List* list,void* data);
void* _List_getData(List* list,int index);
void _List_setData(List* list,int index,void* data);
void _List_delData(List* list,int index);
struct Trem
{
   void* data;
   struct Trem* next;
};
struct List
{
   Trem* start_trem;
   Trem* end_trem;
   void (*append)(List* list,void* data);
   void* (*get)(List* list,int index);
   void (*set)(List* list,int index,void* data);
   void (*del)(List* list,int index);
};
void _List_append(List* list,void* data)
{
   Trem* term = (Trem*)malloc(sizeof(Trem));
   term->data = data;
   term->next = NULL;
   if (list->start_trem == NULL)
   {
      list->start_trem = term;
      list->end_trem = term;
   }
   else
   {
      list->end_trem->next = term;
      list->end_trem = term;
   }
}
void* _List_getData(List* list,int index)
{
   Trem* trem = list->start_trem;
   for (Trem* trem = list->start_trem;trem!=NULL;trem = trem->next)
   {
      if (index == 0)
      {
         return trem;
      }
      index--;
   }
   return NULL;
}
void _List_setData(List* list,int index,void* data)
{
   for (Trem* trem = list->start_trem;trem!=NULL;trem = trem->next)
   {
      if (index == 0)
      {
         trem->data = data;
         return;
      }
      index--;
   }
}
void _List_delData(List* list,int index)
{
   //当要删除列表第一项，更新列表头节点。
   if (index == 0)
   {
      Trem* temp = list->start_trem;
      list->start_trem = list->start_trem->next;
      free(temp);
      return;
   }
   For_List(list)
   {
      if (index == 1)
      {
         Trem* temp = trem->next;
         trem->next = trem->next->next;
         //当删除的项与最后一项相同時，更新列表最后一项。
         if (temp == list->end_trem)list->end_trem = trem;
         free(temp);
         break;
      }
      index--;
   }
}

int main() {
   setbuf(stdout, NULL);
   printf("Hello, World!");
   return 0;
}