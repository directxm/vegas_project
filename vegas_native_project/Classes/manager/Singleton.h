#ifndef __SINGLETON_H__
#define __SINGLETON_H__

// class singleton has the same goal as all singletons: create one instance of
// a class on demand, then dish it out as requested.

template <class T>
class Singleton : private T
{
private:
	Singleton();
	~Singleton();

public:
	static T &instance();
};


template <class T>
inline Singleton<T>::Singleton()
{
	/* no-op */
}

template <class T>
inline Singleton<T>::~Singleton()
{
	/* no-op */
}

template <class T>
/*static*/ T &Singleton<T>::instance()
{
	// function-local static to force this to work correctly at static
	// initialization time.
	static Singleton<T> s_oT;
	return(s_oT);
}

#endif __SINGLETON_H__