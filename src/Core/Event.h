#ifndef DELEGATE_INCLUDE
#define DELEGATE_INCLUDE

#include <functional>
#include <unordered_map>

/*
//Weston McNamara 2020
//Licensed Under MIT https://mit-license.org/
//https://github.com/wmcnamara/delegate

This class is a modification of delegate intended for use in the Crynn game engine.
*/

namespace crynn
{
	/// <summary>
	/// Simple event class
	/// </summary>
	/// <typeparam name="...T">Parameter types</typeparam>
	template<typename ... T>
	class Event
	{
	private:
		typedef std::function<void(T...)> Func_T;
	public:
		//Invokes each function added to this delegate. 
		inline void Invoke(T... param)
		{
			if (m_handlers.empty())
				return;

			for (const auto& key : m_handlers)
			{
				key.second(param...); //Invoke the function
			}
		}

		//Adds a single function to the delegate.
		inline int AddHandler(Func_T func)
		{
			static int nextID = 0;
			m_handlers.insert(std::pair<int, Func_T>(nextID, func));

			//Return the ID, and increment it.
			return nextID++;
		}

		//Removes a single function from the delegate
		inline void RemoveHandler(int ID)
		{
			m_handlers.erase(ID);
		}

	private:
		inline void RemoveAllHandlers()
		{
			m_handlers.clear();
		}

		std::unordered_map<int, Func_T> m_handlers;
	};

	/// <summary>
	/// Creates an event that takes no parameters
	/// </summary>
	template<>
	class Event<void>
	{
	private:
		typedef std::function<void()> Func_T;
	public:
		//Invokes each function added to this delegate. 
		inline void Invoke()
		{
			if (m_handlers.empty())
				return;

			for (const auto& key : m_handlers)
			{
				key.second(); //Invoke the function
			}
		}

		//Adds a single function to the delegate.
		inline int AddHandler(Func_T func)
		{
			static int nextID = 0;
			m_handlers.insert(std::pair<int, Func_T>(nextID, func));

			//Return the ID, and increment it.
			return nextID++;
		}

		//Removes a single function from the delegate using its ID
		inline void RemoveHandler(int ID)
		{
			m_handlers.erase(ID);
		}

		inline void RemoveAllHandlers()
		{
			m_handlers.clear();
		}

	private:
		std::unordered_map<int, Func_T> m_handlers;
	};
}
#endif //DELEGATE_INCLUDE