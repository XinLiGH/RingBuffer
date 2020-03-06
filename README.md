# RingBuffer

模仿kfifo实现的环形缓冲区。程序中涉及到环形缓冲区的概念，详细介绍见维基百科[Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer)。

## 开发环境

* 操作系统：Windows 10 专业版
* IDE：Visual Studio 2017 专业版

## API

* RingBuffer *RingBuffer_Malloc(uint32_t size)
* void RingBuffer_Free(RingBuffer *fifo)
* uint32_t RingBuffer_In(RingBuffer *fifo, const void *in, uint32_t len)
* uint32_t RingBuffer_Out(RingBuffer *fifo, void *out, uint32_t len)
* void RingBuffer_Reset(RingBuffer *fifo)
* uint32_t RingBuffer_Size(RingBuffer *fifo)
* uint32_t RingBuffer_Len(RingBuffer *fifo)
* uint32_t RingBuffer_Avail(RingBuffer *fifo)
* bool RingBuffer_IsEmpty(RingBuffer *fifo)
* bool RingBuffer_IsFull(RingBuffer *fifo)

## 运行效果

![](https://github.com/XinLiGitHub/RingBuffer/raw/master/RingBuffer/RingBuffer/RunningResult.jpg)
