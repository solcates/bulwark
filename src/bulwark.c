#include "shim.h"
#include "session.h"

int init(shim_ctx_t *ctx, shim_val_t *exports, shim_val_t *module) {
    shim_fspec_t funcs[] = {
        // name, cfunc, nargs, data, flags
        SHIM_FS_FULL("load", p11_load, 2, NULL, 0),
        SHIM_FS_FULL("init", p11_init, 2, NULL, 0),
        SHIM_FS_END,
    };

    shim_obj_set_funcs(ctx, exports, funcs);
    return TRUE;
}

SHIM_MODULE(bulwark, init);