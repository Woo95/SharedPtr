#include <iostream>
#include "RefCounter.h"
#include "SharedPtr.h"

class CObject : public CRefCounter
{
public:
	CObject() { std::cout << "Object Created!\n\n"; }
	virtual ~CObject() { std::cout << "Object Destroyed!\n\n"; }
};

int main()
{
	std::cout << "CObject* obj = new CObject;\n";
	CObject* obj = new CObject;

	std::cout << "CSharedPtr<CObject> sharedPtr1 = obj;\n";
	CSharedPtr<CObject> sharedPtr1 = obj;
	std::cout << "-> refCount: " << obj->GetRefCount() << "\n\n";

	std::cout << "CSharedPtr<CObject> sharedPtr2 = obj;\n";
	CSharedPtr<CObject> sharedPtr2 = obj;
	std::cout << "-> refCount: " << obj->GetRefCount() << "\n\n";

	std::cout << "sharedPtr1 = nullptr;\n";
	sharedPtr1 = nullptr;
	std::cout << "-> refCount: " << obj->GetRefCount() << "\n\n";

	std::cout << "sharedPtr2 = nullptr;\n";
	std::cout << "-> refCount: 0\n\n";
	sharedPtr2 = nullptr; // triggers destructor

	return 0;
}