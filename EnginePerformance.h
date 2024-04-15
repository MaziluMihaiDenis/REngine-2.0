#pragma once
#include <thread>

static std::thread LogicThread;
static std::thread LoaderThread;
static std::thread GraphicsThread;

//class Memory
//{
//public:
//	inline static int allocated;
//	inline static int freed;
//	inline static int used;
//
//	static void Print()
//	{
//		used = allocated - freed;
//		std::cout << used << " bytes are used\n";
//	}
//};
//
//void* operator new(size_t size)
//{
//	Memory::allocated += size;
//	std::cout << "Allocating " << size << " bytes\n";
//
//	return malloc(size);
//}
//
//void operator delete(void* block, size_t size)
//{
//	Memory::freed += size;
//	std::cout << "Freeing " << size << " bytes\n";
//	free(block);
//}