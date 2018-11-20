#include <stdio.h>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

typedef struct __LOCK_FILE_INFO__
{
    std::string file_name;
    std::string unlock_time;
}LockFileInfo;

typedef struct __REMOTE_FILE_LOCK__
{
    std::string imei;
    std::string serialcode;
    int type;
    std::string order_id;
    std::string timestamp;
//    std::LockFileInfo> FileInfoVector;
}RemoteFileLock;        //cmd 4 

#if 0
RemoteFileLock rf1
{
    std::string imei;
    std::string serialcode;
    int type;
    std::string order_id;
    std::string timestamp;
    std::vector<LockFileInfo> FileInfoVector[2];
};

#else
RemoteFileLock rfl = {
        .imei = "aa",
        .serialcode = "bb",
        .type = 1,
        .order_id = "cc",
        .timestamp = "dd",

     //   .FileInfoVector(2) = {
     //       .file_name = "file1,
     //       .unlock_time = "1234"
     //   },
     //   {
     //       .file_name = "file1,
     //       .unlock_time = "1234"
     //   }
};
#endif

int GenDevFileLock_1(const RemoteFileLock *lockFile, std::string &push)
{
    if(lockFile != NULL)
    {
        push = "imei=" + lockFile->imei + "&order_id=" + lockFile->order_id + "&serialcode=" + lockFile->serialcode + "&type=" +  std::to_string(lockFile->type) + "&timestamp=" + lockFile->timestamp + "&locked_files={";
        //添加文件列表
//        for(vector<LockFileInfo>::iterator iter = ((RemoteFileLock *)lockFile)->FileInfoVector.begin(); iter != lockFile->FileInfoVector.end(); iter++)
//        {             
//            push = push + "{filename=" + iter->file_name + ", unlock_time=" + iter->unlock_time + "}";
//        }
        push += "}";
    }
    else
    {
        return -1;
    }

    printf("[%s]: %s\n", __FUNCTION__, push.c_str());

    return 0;
}

int main()
{
    std::string str;

    //printf("%s %s\n", rfl.imei.c_str(), rfl.FileInfoVector[0].file_name.c_str());
    GenDevFileLock_1(&rfl, str);
}
