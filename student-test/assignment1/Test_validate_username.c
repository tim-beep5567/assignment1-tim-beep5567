#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    // 1. 取得你在 autotest-validate.c 裡寫的名字
    const char *username_hardcoded = my_username();

    // 2. 取得系統從 conf/username.txt 讀到的名字
    char *username_from_conf = malloc_username_from_conf_file();

    // 3. 檢查兩邊是不是一模一樣
    TEST_ASSERT_EQUAL_STRING_MESSAGE(username_hardcoded, username_from_conf, "名字對不起來！");

    // 4. 釋放記憶體（Linux 開發的好習慣）
    if (username_from_conf != NULL) {
        free(username_from_conf);
    }
}
