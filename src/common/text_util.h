#pragma once

constexpr char TP_HEADERS[] = "#include <vector>\n#include <math.h>\n#include <cassert>\n#include <cstdint>\n\n\n";
constexpr char TP_DLL[] = "\n#if defined(_MSC_VER) || defined(_WIN32)\n#define XGB_DLL extern \"C\" __declspec(dllexport)\n#else\n#define XGB_DLL extern \"C\" __attribute__ ((visibility (\"default\")))\n#endif  // defined(_MSC_VER) || defined(_WIN32)\n\n\n";
constexpr char TP_OBJ_FN[] = "\ninline float obj_fn(float value) {\n  return 1 / (1 + expf(-value));\n}\n\n";
constexpr char CUST_PRED_FN[] = "\nXGB_DLL int CustomPredictFunction(float* values,\n  uint64_t n_rows,\n  uint64_t n_cols,\n  uint64_t* out_len,\n  float* out_result) {\n  assert(n_cols == num_feature);\n  for (int i = 0; i < n_rows; i++) {\n    out_result[i] = base_score;\n  }\n  predict((float(*)[num_feature])values, n_rows, n_cols, out_result);\n  *out_len = n_rows;\n  return 0;\n}\n\n\n";



