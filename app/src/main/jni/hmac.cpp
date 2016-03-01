#include <jni.h>
#include <openssl/hmac.h>

#ifdef __cplusplus
extern "C" {
#endif
jbyteArray
Java_com_example_openssltest_MainActivity_hmacSha256(JNIEnv *env,
                                                     jobject obj,
                                                     jbyteArray content) {
  unsigned char key[] = {0x6B, 0x65, 0x79};

  unsigned int result_len;
  unsigned char result[EVP_MAX_MD_SIZE];

  // get data from java array
  jbyte *data = env->GetByteArrayElements(content, NULL);
  size_t dataLength = env->GetArrayLength(content);

  HMAC(EVP_sha256(),
       key, 3,
       (unsigned char *) data, dataLength,
       result, &result_len);

  // release the array
  env->ReleaseByteArrayElements(content, data, JNI_ABORT);

  // the return value
  jbyteArray return_val = env->NewByteArray(result_len);
  env->SetByteArrayRegion(return_val, 0, result_len, (jbyte *) result);
  return return_val;
}
#ifdef __cplusplus
}
#endif