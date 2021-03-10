#pragma once
#include <utility>
#include <functional>

namespace crynn
{
	/// <summary>
	/// Encapsulates a cache for an object. 
	/// Provides useful functions for checking the validity of a cache, and if it needs to be recalculated.
	/// </summary>
	template<typename T>
	class Cache
	{
		//Constructs a cache object.
		Cache(T& obj, std::function<void(T&)> recalculate) : m_recalculate(recalculate) {}

		inline void Invalidate() { valid = false; }
		inline void Validate() { valid = true; }

		inline bool IsValid() const { return valid; }
		
		void Set(T& _data) { data = std::move(_data); }

		//Returns a constant reference to the data. 
		//Does not invalidate the cache.
		const T& GetData() { return data; }

		//Returns a non const reference to the data.
		//Invalidates the cache.
		T& GetDataNonConst() 
		{ 
			Invalidate(); //when returning a non const reference, invalidate.
			return data;
		}

	private:
		T& data;
		std::function<void(T&)> m_recalculate;
		bool valid = false;
	};
}
