/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "entrypoints/portable/portable_entrypoints.h"
#include "entrypoints/quick/quick_entrypoints.h"
#include "entrypoints/entrypoint_utils.h"

namespace art {

// Interpreter entrypoints.
extern "C" void artInterpreterToInterpreterBridge(Thread* self, MethodHelper& mh,
                                                  const DexFile::CodeItem* code_item,
                                                  ShadowFrame* shadow_frame, JValue* result);
extern "C" void artInterpreterToCompiledCodeBridge(Thread* self, MethodHelper& mh,
                                           const DexFile::CodeItem* code_item,
                                           ShadowFrame* shadow_frame, JValue* result);

// Portable entrypoints.
extern "C" void art_portable_resolution_trampoline(mirror::AbstractMethod*);
extern "C" void art_portable_to_interpreter_bridge(mirror::AbstractMethod*);

// Alloc entrypoints.
extern "C" void* art_quick_alloc_array(uint32_t, void*, int32_t);
extern "C" void* art_quick_alloc_array_with_access_check(uint32_t, void*, int32_t);
extern "C" void* art_quick_alloc_object(uint32_t type_idx, void* method);
extern "C" void* art_quick_alloc_object_with_access_check(uint32_t type_idx, void* method);
extern "C" void* art_quick_check_and_alloc_array(uint32_t, void*, int32_t);
extern "C" void* art_quick_check_and_alloc_array_with_access_check(uint32_t, void*, int32_t);

// Cast entrypoints.
extern "C" uint32_t art_quick_is_assignable(const mirror::Class* klass,
                                                const mirror::Class* ref_class);
extern "C" void art_quick_can_put_array_element(void*, void*);
extern "C" void art_quick_check_cast(void*, void*);

// DexCache entrypoints.
extern "C" void* art_quick_initialize_static_storage(uint32_t, void*);
extern "C" void* art_quick_initialize_type(uint32_t, void*);
extern "C" void* art_quick_initialize_type_and_verify_access(uint32_t, void*);
extern "C" void* art_quick_resolve_string(void*, uint32_t);

// Field entrypoints.
extern "C" int art_quick_set32_instance(uint32_t, void*, int32_t);
extern "C" int art_quick_set32_static(uint32_t, int32_t);
extern "C" int art_quick_set64_instance(uint32_t, void*, int64_t);
extern "C" int art_quick_set64_static(uint32_t, int64_t);
extern "C" int art_quick_set_obj_instance(uint32_t, void*, void*);
extern "C" int art_quick_set_obj_static(uint32_t, void*);
extern "C" int32_t art_quick_get32_instance(uint32_t, void*);
extern "C" int32_t art_quick_get32_static(uint32_t);
extern "C" int64_t art_quick_get64_instance(uint32_t, void*);
extern "C" int64_t art_quick_get64_static(uint32_t);
extern "C" void* art_quick_get_obj_instance(uint32_t, void*);
extern "C" void* art_quick_get_obj_static(uint32_t);

// FillArray entrypoint.
extern "C" void art_quick_handle_fill_data(void*, void*);

// Lock entrypoints.
extern "C" void art_quick_lock_object(void*);
extern "C" void art_quick_unlock_object(void*);

// Math entrypoints.
extern "C" double art_quick_fmod(double, double);
extern "C" float art_quick_fmodf(float, float);
extern "C" double art_quick_l2d(int64_t);
extern "C" float art_quick_l2f(int64_t);
extern "C" int64_t art_quick_d2l(double);
extern "C" int64_t art_quick_f2l(float);
extern "C" int32_t art_quick_idivmod(int32_t, int32_t);
extern "C" int64_t art_quick_ldiv(int64_t, int64_t);
extern "C" int64_t art_quick_ldivmod(int64_t, int64_t);
extern "C" int64_t art_quick_lmul(int64_t, int64_t);
extern "C" uint64_t art_quick_lshl(uint64_t, uint32_t);
extern "C" uint64_t art_quick_lshr(uint64_t, uint32_t);
extern "C" uint64_t art_quick_lushr(uint64_t, uint32_t);

// Intrinsic entrypoints.
extern "C" int32_t art_quick_memcmp16(void*, void*, int32_t);
extern "C" int32_t art_quick_indexof(void*, uint32_t, uint32_t, uint32_t);
extern "C" int32_t art_quick_string_compareto(void*, void*);
extern "C" void* art_quick_memcpy(void*, const void*, size_t);

// Invoke entrypoints.
extern "C" void art_quick_resolution_trampoline(mirror::AbstractMethod*);
extern "C" void art_quick_to_interpreter_bridge(mirror::AbstractMethod*);
extern "C" void art_quick_invoke_direct_trampoline_with_access_check(uint32_t, void*);
extern "C" void art_quick_invoke_interface_trampoline(uint32_t, void*);
extern "C" void art_quick_invoke_interface_trampoline_with_access_check(uint32_t, void*);
extern "C" void art_quick_invoke_static_trampoline_with_access_check(uint32_t, void*);
extern "C" void art_quick_invoke_super_trampoline_with_access_check(uint32_t, void*);
extern "C" void art_quick_invoke_virtual_trampoline_with_access_check(uint32_t, void*);

// Thread entrypoints.
extern void CheckSuspendFromCode(Thread* thread);
extern "C" void art_quick_test_suspend();

// Throw entrypoints.
extern "C" void art_quick_deliver_exception(void*);
extern "C" void art_quick_throw_array_bounds(int32_t index, int32_t limit);
extern "C" void art_quick_throw_div_zero();
extern "C" void art_quick_throw_no_such_method(int32_t method_idx);
extern "C" void art_quick_throw_null_pointer_exception();
extern "C" void art_quick_throw_stack_overflow(void*);

void InitEntryPoints(InterpreterEntryPoints* ipoints, JniEntryPoints* jpoints,
                     PortableEntryPoints* ppoints, QuickEntryPoints* qpoints) {
  // Interpreter
  ipoints->pInterpreterToInterpreterBridge = artInterpreterToInterpreterBridge;
  ipoints->pInterpreterToCompiledCodeBridge = artInterpreterToCompiledCodeBridge;

  // JNI
  jpoints->pDlsymLookup = art_jni_dlsym_lookup_stub;

  // Portable
  ppoints->pPortableResolutionTrampoline = art_portable_resolution_trampoline;
  ppoints->pPortableToInterpreterBridge = art_portable_to_interpreter_bridge;

  // Alloc
  qpoints->pAllocArray = art_quick_alloc_array;
  qpoints->pAllocArrayWithAccessCheck = art_quick_alloc_array_with_access_check;
  qpoints->pAllocObject = art_quick_alloc_object;
  qpoints->pAllocObjectWithAccessCheck = art_quick_alloc_object_with_access_check;
  qpoints->pCheckAndAllocArray = art_quick_check_and_alloc_array;
  qpoints->pCheckAndAllocArrayWithAccessCheck = art_quick_check_and_alloc_array_with_access_check;

  // Cast
  qpoints->pInstanceofNonTrivial = art_quick_is_assignable;
  qpoints->pCanPutArrayElement = art_quick_can_put_array_element;
  qpoints->pCheckCast = art_quick_check_cast;

  // DexCache
  qpoints->pInitializeStaticStorage = art_quick_initialize_static_storage;
  qpoints->pInitializeTypeAndVerifyAccess = art_quick_initialize_type_and_verify_access;
  qpoints->pInitializeType = art_quick_initialize_type;
  qpoints->pResolveString = art_quick_resolve_string;

  // Field
  qpoints->pSet32Instance = art_quick_set32_instance;
  qpoints->pSet32Static = art_quick_set32_static;
  qpoints->pSet64Instance = art_quick_set64_instance;
  qpoints->pSet64Static = art_quick_set64_static;
  qpoints->pSetObjInstance = art_quick_set_obj_instance;
  qpoints->pSetObjStatic = art_quick_set_obj_static;
  qpoints->pGet32Instance = art_quick_get32_instance;
  qpoints->pGet64Instance = art_quick_get64_instance;
  qpoints->pGetObjInstance = art_quick_get_obj_instance;
  qpoints->pGet32Static = art_quick_get32_static;
  qpoints->pGet64Static = art_quick_get64_static;
  qpoints->pGetObjStatic = art_quick_get_obj_static;

  // FillArray
  qpoints->pHandleFillArrayData = art_quick_handle_fill_data;

  // JNI
  qpoints->pJniMethodStart = JniMethodStart;
  qpoints->pJniMethodStartSynchronized = JniMethodStartSynchronized;
  qpoints->pJniMethodEnd = JniMethodEnd;
  qpoints->pJniMethodEndSynchronized = JniMethodEndSynchronized;
  qpoints->pJniMethodEndWithReference = JniMethodEndWithReference;
  qpoints->pJniMethodEndWithReferenceSynchronized = JniMethodEndWithReferenceSynchronized;

  // Locks
  qpoints->pLockObject = art_quick_lock_object;
  qpoints->pUnlockObject = art_quick_unlock_object;

  // Math
  // points->pCmpgDouble = NULL;  // Not needed on x86.
  // points->pCmpgFloat = NULL;  // Not needed on x86.
  // points->pCmplDouble = NULL;  // Not needed on x86.
  // points->pCmplFloat = NULL;  // Not needed on x86.
  qpoints->pFmod = art_quick_fmod;
  qpoints->pL2d = art_quick_l2d;
  qpoints->pFmodf = art_quick_fmodf;
  qpoints->pL2f = art_quick_l2f;
  // points->pD2iz = NULL;  // Not needed on x86.
  // points->pF2iz = NULL;  // Not needed on x86.
  qpoints->pIdivmod = art_quick_idivmod;
  qpoints->pD2l = art_quick_d2l;
  qpoints->pF2l = art_quick_f2l;
  qpoints->pLdiv = art_quick_ldiv;
  qpoints->pLdivmod = art_quick_ldivmod;
  qpoints->pLmul = art_quick_lmul;
  qpoints->pShlLong = art_quick_lshl;
  qpoints->pShrLong = art_quick_lshr;
  qpoints->pUshrLong = art_quick_lushr;

  // Intrinsics
  qpoints->pIndexOf = art_quick_indexof;
  qpoints->pMemcmp16 = art_quick_memcmp16;
  qpoints->pStringCompareTo = art_quick_string_compareto;
  qpoints->pMemcpy = art_quick_memcpy;

  // Invocation
  qpoints->pQuickResolutionTrampoline = art_quick_resolution_trampoline;
  qpoints->pQuickToInterpreterBridge = art_quick_to_interpreter_bridge;
  qpoints->pInvokeDirectTrampolineWithAccessCheck = art_quick_invoke_direct_trampoline_with_access_check;
  qpoints->pInvokeInterfaceTrampoline = art_quick_invoke_interface_trampoline;
  qpoints->pInvokeInterfaceTrampolineWithAccessCheck = art_quick_invoke_interface_trampoline_with_access_check;
  qpoints->pInvokeStaticTrampolineWithAccessCheck = art_quick_invoke_static_trampoline_with_access_check;
  qpoints->pInvokeSuperTrampolineWithAccessCheck = art_quick_invoke_super_trampoline_with_access_check;
  qpoints->pInvokeVirtualTrampolineWithAccessCheck = art_quick_invoke_virtual_trampoline_with_access_check;

  // Thread
  qpoints->pCheckSuspend = CheckSuspendFromCode;
  qpoints->pTestSuspend = art_quick_test_suspend;

  // Throws
  qpoints->pDeliverException = art_quick_deliver_exception;
  qpoints->pThrowArrayBounds = art_quick_throw_array_bounds;
  qpoints->pThrowDivZero = art_quick_throw_div_zero;
  qpoints->pThrowNoSuchMethod = art_quick_throw_no_such_method;
  qpoints->pThrowNullPointer = art_quick_throw_null_pointer_exception;
  qpoints->pThrowStackOverflow = art_quick_throw_stack_overflow;
};

}  // namespace art
