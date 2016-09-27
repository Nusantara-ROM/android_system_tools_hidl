/*
 * Copyright (C) 2016 The Android Open Source Project
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

#ifndef TYPE_DEF_H_

#define TYPE_DEF_H_

#include "NamedType.h"

namespace android {

struct TypeDef : public NamedType {
    TypeDef(const char* localName, Type *type);

    const ScalarType *resolveToScalarType() const override;

    Type *referencedType() const;

    bool isInterface() const override;
    bool isEnum() const override;
    bool isTypeDef() const override;
    bool needsEmbeddedReadWrite() const override;
    bool resultNeedsDeref() const override;

    status_t emitTypeDeclarations(Formatter &out) const override;

private:
    Type *mReferencedType;

    DISALLOW_COPY_AND_ASSIGN(TypeDef);
};

}  // namespace android

#endif  // TYPE_DEF_H_

