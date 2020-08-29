#ifndef DELEGATE_INCLUDE
#define DELEGATE_INCLUDE

#include <functional>
#include <map>

/*
//Weston McNamara 2020
//Licensed Under MIT https://mit-license.org/
//https://github.com/wmcnamara/delegate

//Delegate is a single header, lightweight and easy to use abstraction for storing functions and callbacks.
//When you call AddHandler, a integer type containing the ID is returned. To call RemoveHandler, you must pass this integer.
//If you know you might delete the handler you add, be sure to keep track of this number.
//Uses std::map to represent ID/Function data.
*/

#ifndef DELEGATE_API
#define DELEGATE_API //__declspec(dllexport)
#endif

//You can define DELEGATE_NOEXCEPT to nothing to allow throwing exceptions. By default, it will not.
#ifndef DELEGATE_NOEXCEPT
#define DELEGATE_NOEXCEPT noexcept
#endif

template<typename T>
class Delegate
{
private:
	typedef std::function<void(T)> Func_T;

public:
	//Invokes each function added to this delegate. 
	DELEGATE_API void Invoke(T param) DELEGATE_NOEXCEPT
	{
		if (m_handlers.empty())
			return;

		for (const auto& key : m_handlers)
		{
			key.second(param); //Invoke the function
		}		
	}

	//Adds a single function to the delegate.
	DELEGATE_API int AddHandler(Func_T func) DELEGATE_NOEXCEPT
	{
		static int nextID = 0;
		m_handlers.insert(std::pair<int, Func_T>(nextID, func));

		//Return the ID, and increment it.
		return nextID++;
	}

	//Removes a single function from the delegate
	DELEGATE_API void RemoveHandler(int ID) DELEGATE_NOEXCEPT
	{
		m_handlers.erase(ID);
	}

	DELEGATE_API void RemoveAllHandlers() DELEGATE_NOEXCEPT
	{
		m_handlers.clear();
	}

private:
    std::map<int, Func_T> m_handlers;
};

#endif //DELEGATE_INCLUDE