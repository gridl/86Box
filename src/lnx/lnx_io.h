#ifndef SRC_LNX_LNX_IO_H_
#define SRC_LNX_LNX_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

FILE* _wfopen(const wchar_t* fn, const wchar_t* mode);
int _wremove(const wchar_t* path);
int _wchdir(const wchar_t* path);

#ifdef __cplusplus
}
#endif

#endif /* SRC_LNX_LNX_IO_H_ */
