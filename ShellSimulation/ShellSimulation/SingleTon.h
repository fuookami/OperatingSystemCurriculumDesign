#pragma once

#include <memory>

template <class T>
class SingleTon
{
public:
	static T *instance(void);
protected:
	SingleTon(void) {};
	SingleTon(const SingleTon &) {};
	~SingleTon(void) {};
	SingleTon &operator=(const SingleTon &) {};
private:
	static std::shared_ptr<T> m_pInstance;
};

template <class T>
std::shared_ptr<T> SingleTon<T>::m_pInstance = nullptr;

template <class T>
T *SingleTon<T>::instance(void)
{
	if (m_pInstance == nullptr)
	{
		m_pInstance.reset(new T());
	}
	return m_pInstance.get();
}