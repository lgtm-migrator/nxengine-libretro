
#include <stdio.h>
#include "FileBuffer.h"
#include "../nx.h"

FileBuffer::FileBuffer()
{
	fMaxSize = 0;
	fFP = NULL;
}

void FileBuffer::SetBufferSize(int maxsize)
{
	fMaxSize = maxsize;
}

void FileBuffer::SetFile(FILE *fp)
{
	fFP = fp;
}

void FileBuffer::Write8(uint8_t data)
{
	fBuffer.Append8(data);
	CheckFlush(fMaxSize);
}

void FileBuffer::Write16(uint16_t data)
{
	fBuffer.Append16(data);
	CheckFlush(fMaxSize);
}

void FileBuffer::Write32(uint32_t data)
{
	fBuffer.Append32(data);
	CheckFlush(fMaxSize);
}

void FileBuffer::CheckFlush(int maxsize)
{
   if (fBuffer.Length() >= maxsize)
   {
      if (fFP)
      {
         //NX_LOG("CheckFlush wrote %d bytes", fBuffer.Length()\n);
         fwrite(fBuffer.Data(), fBuffer.Length(), 1, fFP);
         fBuffer.Clear();
      }
   }
}

void FileBuffer::Flush()
{
	CheckFlush(0);
}

void FileBuffer::Dump()
{
	fBuffer.Clear();
}
