#include <map>
#include <list>

using namespace std;

class UserProfile{
public:
	long userId; //用户ID
          map<long, double> preferTags; //偏好标签：key=标签ID，value=偏好得分
};

class Product{
public:
	long productId; //商品ID
    long tags[]; //标签ID列表
};

class ProductsPool{
         public list<Product> products; //所有商品
};


List<Long> recommend(UserProfile userProfile, ProductsPool productsPool)
 {

 }