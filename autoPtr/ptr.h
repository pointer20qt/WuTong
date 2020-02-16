#pragma once

template<class T> class T_autoPtr
{
	T* obj = nullptr;
public:
	T_autoPtr(T* ptr) :obj(ptr)
	{

	}
	T_autoPtr() = default;
	~T_autoPtr()
	{
		delete obj;
	}
	T_autoPtr(T_autoPtr<T>& ptr) :obj(ptr.release())
	{

	}
	T_autoPtr& operator=(T_autoPtr<T>& ptr)
	{
		obj = ptr.release();
		return *this;
	}
	void reset(T* newPtr=nullptr)
	{
		delete obj;
		obj = newPtr;
	}
	T* release()
	{
		auto temP = obj;
		obj = nullptr;
		return temP;
	}
	T& operator* ()
	{
		return *obj;
	}
	T* operator-> ()
	{
		return obj;
	}
	T* get()
	{
		return obj;
	}
};