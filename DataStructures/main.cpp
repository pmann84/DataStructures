#include "array.h"
#include "vector.h"

#include <iostream>
#include <array>
#include <vector>

class foo 
{
public:
   int data = 1;
};

struct vector3
{
   float x = 0.0f, y = 0.0f, z = 0.0f;
};

struct dummy_object
{
   uint64_t i = 0;
   std::string s = "";
   //vector3 vec;

   dummy_object() {}
   dummy_object(uint64_t ival, std::string sval) : i(ival), s(sval) {}

   ~dummy_object()
   {
      std::cout << "dummy_object DESTROYED" << std::endl;
   }

   dummy_object(const dummy_object& other)
   {
      std::cout << "dummy_object COPY" << std::endl;
   }

   dummy_object(const dummy_object&& other)
   {
      std::cout << "dummy_object MOVE" << std::endl;
   }

   dummy_object& operator=(const dummy_object& other)
   {
      std::cout << "dummy_object COPY" << std::endl;
      i = other.i;
      s = other.s;
      return *this;
   }

   dummy_object& operator=(const dummy_object&& other)
   {
      std::cout << "dummy_object MOVE" << std::endl;
      i = other.i;
      s = other.s;
      return *this;
   }
};

template<typename CONTAINER_TYPE>
void print_collection(const CONTAINER_TYPE& coll)
{
   for (size_t i = 0; i < coll.size(); ++i)
   {
      std::cout << coll[i] << " ";
   }
   std::cout << std::endl;
}

template<>
void print_collection(const ds::vector<dummy_object>& coll)
{
   for (size_t i = 0; i < coll.size(); ++i)
   {
      std::cout << "(" << coll[i].i << ", " << coll[i].s << ") ";
   }
   std::cout << std::endl;
}

int main()
{
   ds::array<uint64_t, 5> arr;
   std::cout << arr.size() << std::endl;

   std::fill_n(&arr[0], arr.size(), 0);

   print_collection(arr);

   arr[1] = 5;
   arr[3] = 9;

   print_collection(arr);

   ds::array<std::string, 3> s_arr;
   s_arr[0] = "Hello";
   s_arr[1] = ",";
   s_arr[2] = "World!";

   print_collection(s_arr);

   ds::vector<uint64_t> vec;
   print_collection(vec);

   ds::vector<dummy_object> dvec;
   dvec.push_back(dummy_object( 1, "Hello" ));
   dvec.push_back(dummy_object( 9, "My Goodness" ));
   dvec.push_back(dummy_object( 20, "Well" ));
   print_collection(dvec);

   ds::vector<dummy_object> dvece;
   dvece.emplace_back(1, "Hello");
   dvece.emplace_back(9, "My Goodness");
   dvece.emplace_back(20, "Well");
   print_collection(dvece);
   dvece.clear();
   print_collection(dvece);
   //std::vector<foo*> vpF;
   //std::vector<foo*> vpF2;
   //{
   //   std::unique_ptr<foo> pF = std::make_unique<foo>();

   //   vpF.emplace_back(pF.get());
   //   vpF2.emplace_back(pF.get());
   //   pF.release();
   //}
   //std::cout << vpF[0]->data << std::endl;
   std::cin.get();
   return 0;
}