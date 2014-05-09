#ifndef _BATONS_H_
#define _BATONS_H_

#include "shim.h"
#include "pkcs11.h"

typedef struct bulwark_ctx_s {
    shim_persistent_t* instance;
    shim_persistent_t* logger;
    long chunkSize;
} bulwark_ctx_t;


#endif /* _BATONS_H_ */
