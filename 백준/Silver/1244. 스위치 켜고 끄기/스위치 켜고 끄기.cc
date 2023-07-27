#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>


using namespace std;


int main() {

    int n;
    int m;
    int male;
    int check;

    int check_repeat;
    int check_right;
    int feamale_count = 0;
    int switching[104] = { 0, };



    //vector<int> switching;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> switching[i];

    }
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> male >> check;

        if (male == 1) //남학생 --> 완벽
        {
            //cin >> check;
            check_repeat = check;

            while ((check - 1) < n)
            {
                if (switching[check - 1] == 0)
                {
                    switching[check - 1] = 1;
                    check += check_repeat;
                }
                else if (switching[check - 1] == 1)
                {
                    switching[check - 1] = 0;
                    check += check_repeat;

                }

            }
            check_repeat = 0;
        }
        else //여학생 --> 자기 자신은 항상 바뀐다.
        {
            //cin >> check;

            if (check == 1)
            {
                if (switching[check - 1] == 0)
                {
                    switching[check - 1] = 1;
                }
                else
                {
                    switching[check - 1] = 0;
                }

            }
            else if (check > 1)
            {
                check_repeat = check - 2;
                check_right = check;
                while (1)
                {
                    if ((check_repeat < 0) || (check_right > n - 1))
                    {
                        break;
                    }

                    if (switching[check_repeat] == switching[check_right])
                    {
                        feamale_count++;
                    }
                    else
                    {
                        break;
                    }
                    //if ((check_repeat >= 0) && (check_right <= n - 1))
                    //{
                    check_repeat--;
                    check_right++;
                    //}


                }
                if (feamale_count > 0)
                {
                    for (int i = (check - 1) - feamale_count; i <= check - 1 + feamale_count; i++)
                    {
                        if (switching[i] == 0)
                        {
                            switching[i] = 1;
                        }
                        else
                        {
                            switching[i] = 0;
                        }
                    }
                }
                else if (feamale_count == 0)
                {
                    if (switching[check - 1] == 0)
                    {
                        switching[check - 1] = 1;
                    }
                    else
                    {
                        switching[check - 1] = 0;
                    }


                }
                feamale_count = 0;
            }


        }
    }


    for (int j = 1; j <= n; j++)
    {
        cout << switching[j-1] << " ";
        if (j % 20 == 0)
        {
                cout << endl;
        }

    }


    //delete[] switching;

    return 0;
}