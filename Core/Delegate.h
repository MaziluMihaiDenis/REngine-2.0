#pragma once

#include <vector>

template<typename ...Args>
class Delegate
{
	typedef void(*fptr)(void* objPointer, Args... args);
public:
	Delegate() = default;

private:
	std::vector<void*> ObjectPointer;
	std::vector<fptr> FunctionPointer;

public:
	template<typename T, void(T::* Function)(Args...)>
	void bind_member_function(T* obj)
	{
		ObjectPointer.push_back(obj);
		FunctionPointer.push_back(&make_function_pointer<T, Function>);
	}

	void operator()(Args ...args) const
	{
		for (int i = 0; i < ObjectPointer.size(); i++)
			(*FunctionPointer[i])(ObjectPointer[i], args...);
	}

private:
	template<typename T, void(T::* Function)(Args...)>
	static void make_function_pointer(void* obj, Args... args)
	{
		T* obj_ptr = static_cast<T*>(obj);
		return (obj_ptr->*Function)(args...);
	}
};