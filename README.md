# Bulwark:  Node.js + PKCS#11

Bulwark is a native Node.js addon that utilizes the RSA PKCS#11 API (v2.20) to perform cryptographic operations.  This module, specifically, acts as a common layer upon which various vendor-specific additions can be made. 

Bulwark utilizes tjfontaine's excellent [`node-addon-layer`](https://github.com/tjfontaine/node-addon-layer) which provides a nice Node.js add-on interface for C.  This allows us to avoid writing the add-on in C++.  It also gives us a clean upgrade path forward, when the `node-addon-layer` is baked into the Node.js core.

### Contributing to Bulwark

Contributions to Bulwark are welcome, however there are some fairly interesting conventions when dealing with native add-ons in Node.js (and specifically Bulwark) that you should be aware of.

Bulwark's integration tests are divided between the native add-on, and the JavaScript that wraps it.  If you take time to read through the C code, you'll notice a distinct lack of input validation.  This is quite intentional.  **Input validation should happen at the JavaScript layer -- not in the native layer**.

This means that the integration tests for the native add-on are really only covering the "happy path" where all inputs are valid.  You'll see quite a bit more test coverage over the JavaScript wrapper as a result.  In general, if you wish to contribute to Bulwark, please follow some simple guidelines:

 * Keep the C code very clean and terse.  Validate input data within the JavaScript boundary, and only pass valid data down to the native C level.
 * JavaScript object creation and especially **modification** within the native boundary is very expensive.  Because of this, the only place we do it is when passing an `Error` object back to a callback function.
 * For performance reasons, make sure that you only interact with the native layer using primitive types.  Primitive types are:  `Number`, `Integer`, `String`, `Buffer`, `Function`, and external pointers (think handles).