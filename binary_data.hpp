#ifndef JAVA_BINARY_DATA_BINARY_DATA_HPP_INCLUDED
#define JAVA_BINARY_DATA_BINARY_DATA_HPP_INCLUDED
#pragma once

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

namespace Sam {
	namespace JavaBinaryData {
		class Data {
		public:
			int test;

		private:
			friend class boost::serialization::access;
			template<class Archive>
			void serialize(Archive& ar, const unsigned int version) {
				ar& test;
			}
		};
	}
}
#endif	// JAVA_BINARY_DATA_BINARY_DATA_HPP_INCLUDED
