/**
  ******************************************************************************
  * @file    main.c
  * @author  XinLi
  * @version v1.1
  * @date    15-January-2018
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * <h2><center>Copyright &copy; 2018 XinLi</center></h2>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  *
  ******************************************************************************
  */

/* Header includes -----------------------------------------------------------*/
#include "RingBuffer.h"
#include <stdio.h>
#include <windows.h>

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None.
  * @return None.
  */
int main(void)
{
  uint8_t data[256] = {0};

  for(int i = 0; i < sizeof(data); i++)
  {
    data[i] = i;
  }

  RingBuffer *fifo = RingBuffer_Malloc(sizeof(data));

  if(fifo != NULL)
  {
    printf("FIFO创建成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
           RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));

    if(RingBuffer_IsFull(fifo) == true)
    {
      printf("FIFO满了！！！\n");
    }
    else
    {
      printf("FIFO没满！！！\n");
    }

    if(RingBuffer_IsEmpty(fifo) == true)
    {
      printf("FIFO空了！！！\n");
    }
    else
    {
      printf("FIFO没空！！！\n");
    }

    printf("\n");

    for(;;)
    {
      {
        if(RingBuffer_In(fifo, data, sizeof(data) / 2) > 0)
        {
          printf("FIFO写入成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO写入失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        uint8_t rdata[64] = {0};
        uint8_t len       = RingBuffer_Out(fifo, rdata, sizeof(rdata));

        if(len > 0)
        {
          printf("从FIFO中读出的数据，长度：%d\n", len);

          for(int i = 0; i < len; i++)
          {
            printf("%d ", rdata[i]);
          }

          printf("\n");

          printf("FIFO读取成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO读取失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        RingBuffer_Reset(fifo);
        printf("FIFO清空成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
               RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        if(RingBuffer_In(fifo, data, sizeof(data)) > 0)
        {
          printf("FIFO写入成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO写入失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        if(RingBuffer_In(fifo, data, sizeof(data)) > 0)
        {
          printf("FIFO写入成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO写入失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        uint8_t  rdata[256] = {0};
        uint16_t len        = RingBuffer_Out(fifo, rdata, sizeof(rdata));

        if(len > 0)
        {
          printf("从FIFO中读出的数据，长度：%d\n", len);

          for(int i = 0; i < len; i++)
          {
            printf("%d ", rdata[i]);
          }

          printf("\n");

          printf("FIFO读取成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO读取失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n");

      {
        uint8_t  rdata[256] = {0};
        uint16_t len        = RingBuffer_Out(fifo, rdata, sizeof(rdata));

        if(len > 0)
        {
          printf("从FIFO中读出的数据，长度：%d\n", len);

          for(int i = 0; i < len; i++)
          {
            printf("%d ", rdata[i]);
          }

          printf("\n");

          printf("FIFO读取成功，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }
        else
        {
          printf("FIFO读取失败，FIFO大小：%d，使用大小：%d，剩余大小：%d\n",
                 RingBuffer_Size(fifo), RingBuffer_Len(fifo), RingBuffer_Avail(fifo));
        }

        if(RingBuffer_IsFull(fifo) == true)
        {
          printf("FIFO满了！！！\n");
        }
        else
        {
          printf("FIFO没满！！！\n");
        }

        if(RingBuffer_IsEmpty(fifo) == true)
        {
          printf("FIFO空了！！！\n");
        }
        else
        {
          printf("FIFO没空！！！\n");
        }
      }

      printf("\n\n\n");
      Sleep(5000);
    }
  }
  else
  {
    printf("FIFO创建失败\n");
  }

  for(;;)
  {

  }
}
