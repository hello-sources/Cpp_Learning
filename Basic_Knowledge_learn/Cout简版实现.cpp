/*************************************************************************
	> File Name: Cout简版实现.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 07 Jan 2021 11:17:16 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

namespace haizei {
	class ostream {
	public :
		ostream &operator<<(int x) {
			printf("%d", x);
			return *this;
		}
		ostream &operator<<(const std::string &str) {
			printf("%s", str.c_str());
			return *this;
		}
		ostream &operator<<(const char &ch) {
			printf("%c", ch);
			return *this;
		}
		ostream &operator<<(const double &a) {
			//方法一 
			char e_str[20];
			sprintf(e_str, "%-6g", a);
			for (int i = 0; e_str[i]; i++) {
				if (e_str[i]-' ') continue;
				e_str[i] = 0;
				break;
			}
			printf("%s", e_str);
			return *this;
//			方法二 
//			int e_num, temp;
//			sprintf(e_str, "%.5e", a);
//			sscanf(e_str, "%d.%de%d", &temp, &temp, &e_num);
//			if (e_num >= 6 || e_num <= -5) {
//				printf("%s", e_str);
//			} else {
//				temp = 5 - e_num;
//				sprintf(e_str, "%%.%dlf", temp);
//				printf(e_str, a);
//			}
//			return *this;

			//方法三
			//printf("%g", a);
			//return *this; 
		}
	};
	char endl = '\n';
	ostream cout;
}

int main() {
	haizei::cout << "hello world" << haizei::endl;
	haizei::cout << 123 << haizei::endl;
	haizei::cout << 123.456 << haizei::endl;
	haizei::cout << 123.45 << haizei::endl;
	haizei::cout << 123. << haizei::endl;
	haizei::cout << 123. << 123. << haizei::endl;
	std::cout << 123. << 123. << std::endl;
	haizei::cout << 123.4545454545 << haizei::endl;
	haizei::cout << 1.4545454545 << haizei::endl;
	double a = 3787878787878780.;
	for (int i = 0; i < 20; i++) {
		a /= 10;
		haizei::cout << i << " " << a << haizei::endl;
		//printf(" %.5e\n", a);
	}
	printf("%lf\n", 123.456);
	printf("%lf\n", 123.456);
	printf("%lf\n", 123.);
	return 0;
}
