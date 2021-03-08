#pragma once
#include <utility>

namespace crynn
{
	/// <summary>
	/// Encapsulates a cache for an object. 
	/// Provides useful functions for checking the validity of a cache, and if it needs to be recalculated.
	/// </summary>
	/// <typeparam name="T">Object to be cached</typeparam>
	template<typename T>
	class Cache
	{
		inline void Invalidate() { valid = false; }
		inline void Validate() { valid = true; }

		inline bool IsValid() const { return valid; }

		void Set(T&& _data) { data = std::move(_data); }
		void Set(T& _data) { data = std::move(_data); }

		const T& GetData() { return data; }

		T& GetData() 
		{ 
			Invalidate(); //when returning a non const reference, invalidate.
			return data;
		}

	private:
		T data;
		bool valid = true;
	};
}