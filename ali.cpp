#include <map>
#include <list>

using namespace std;

class UserProfile{
public:
	long userId; //�û�ID
          map<long, double> preferTags; //ƫ�ñ�ǩ��key=��ǩID��value=ƫ�õ÷�
};

class Product{
public:
	long productId; //��ƷID
    long tags[]; //��ǩID�б�
};

class ProductsPool{
         public list<Product> products; //������Ʒ
};


List<Long> recommend(UserProfile userProfile, ProductsPool productsPool)
 {

 }