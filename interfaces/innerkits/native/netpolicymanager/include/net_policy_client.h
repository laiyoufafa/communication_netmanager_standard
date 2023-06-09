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

#ifndef NET_POLICY_MANAGER_H
#define NET_POLICY_MANAGER_H

#include "singleton.h"

#include "i_net_policy_service.h"
#include "net_policy_constants.h"

namespace OHOS {
namespace NetManagerStandard {
class NetPolicyClient {
    DECLARE_DELAYED_SINGLETON(NetPolicyClient)

public:
    NetPolicyResultCode SetUidPolicy(uint32_t uid, NetUidPolicy policy);
    NetUidPolicy GetUidPolicy(uint32_t uid);
    std::vector<uint32_t> GetUids(NetUidPolicy policy);
    bool IsUidNetAccess(uint32_t uid, bool metered);
    bool IsUidNetAccess(uint32_t uid, const std::string &ifaceName);

private:
    class NetPolicyDeathRecipient : public IRemoteObject::DeathRecipient {
    public:
        explicit NetPolicyDeathRecipient(NetPolicyClient &client) : client_(client) {}
        ~NetPolicyDeathRecipient() override = default;
        void OnRemoteDied(const wptr<IRemoteObject> &remote) override
        {
            client_.OnRemoteDied(remote);
        }

    private:
        NetPolicyClient &client_;
    };

private:
    sptr<INetPolicyService> GetProxy();
    void OnRemoteDied(const wptr<IRemoteObject> &remote);

private:
    std::mutex mutex_;
    sptr<INetPolicyService> netPolicyService_;
    sptr<IRemoteObject::DeathRecipient> deathRecipient_;
};
} // namespace NetManagerStandard
} // namespace OHOS
#endif // NET_POLICY_MANAGER_H
