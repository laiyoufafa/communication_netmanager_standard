/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NET_SUPPLIER_INFO_H
#define NET_SUPPLIER_INFO_H

#include <string>

#include "parcel.h"

namespace OHOS {
namespace NetManagerStandard {
struct NetSupplierInfo : public Parcelable {
    bool isAvailable_ = false;
    bool isRoaming_ = false;
    uint8_t strength_ = 0x00;
    uint32_t frequency_ = 0x00;

    virtual bool Marshalling(Parcel &parcel) const override;
    static sptr<NetSupplierInfo> Unmarshalling(Parcel &parcel);
    static bool Marshalling(Parcel &parcel, const sptr<NetSupplierInfo> &object);
    std::string ToString(const std::string &tab) const;
};
} // namespace NetManagerStandard
} // namespace OHOS
#endif // NET_SUPPLIER_INFO_H