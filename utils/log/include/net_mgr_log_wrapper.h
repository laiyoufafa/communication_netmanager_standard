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

#ifndef NET_MGR_LOG_WRAPPER_H
#define NET_MGR_LOG_WRAPPER_H

#include <string>
#include "hilog/log.h"

namespace OHOS {
namespace NetManagerStandard {
enum class NetMgrLogLevel {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    FATAL,
};

class NetMgrLogWrapper {
public:
    static bool JudgeLevel(const NetMgrLogLevel &level);

    static void SetLogLevel(const NetMgrLogLevel &level)
    {
        level_ = level;
    }

    static const NetMgrLogLevel &GetLogLevel()
    {
        return level_;
    }

    static std::string GetBriefFileName(const std::string &file);

private:
    static NetMgrLogLevel level_;
};

#ifndef NETMGR_LOG_TAG
#define NETMGR_LOG_TAG "NetMgrSubsystem"
#endif

static constexpr OHOS::HiviewDFX::HiLogLabel NET_MGR_LABEL = {LOG_CORE, LOG_DOMAIN, NETMGR_LOG_TAG};

#ifdef NETMGR_DEBUG
#define PRINT_LOG(op, fmt, ...)                                                                               \
    (void)OHOS::HiviewDFX::HiLog::op(NET_MGR_LABEL, "[%{public}s-(%{public}s:%{public}d)]" fmt, __FUNCTION__, \
        __FILE_NAME__, __LINE__, ##__VA_ARGS__)
#else
#define PRINT_LOG(op, fmt, ...)
#endif
#define NETMGR_LOGE(fmt, ...) PRINT_LOG(Error, fmt, ##__VA_ARGS__)
#define NETMGR_LOGW(fmt, ...) PRINT_LOG(Warn, fmt, ##__VA_ARGS__)
#define NETMGR_LOGI(fmt, ...) PRINT_LOG(Info, fmt, ##__VA_ARGS__)
#define NETMGR_LOGF(fmt, ...) PRINT_LOG(Fatal, fmt, ##__VA_ARGS__)
} // namespace NetManagerStandard
} // namespace OHOS
#endif // NET_MGR_LOG_WRAPPER_H