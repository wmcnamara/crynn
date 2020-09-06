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

namespace Crynn
{
	namespace Events
	{
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

			inline void RemoveAllHandlers()
			{
				m_handlers.clear();
			}

		private:
			std::map<int, Func_T> m_handlers;
		};

		//Template specialization for no parameter
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

			//Removes a single function from the delegate
			inline void RemoveHandler(int ID)
			{
				m_handlers.erase(ID);
			}

			inline void RemoveAllHandlers()
			{
				m_handlers.clear();
			}

		private:
			std::map<int, Func_T> m_handlers;
		};
	}
}
#endif //DELEGATE_INCLUDE