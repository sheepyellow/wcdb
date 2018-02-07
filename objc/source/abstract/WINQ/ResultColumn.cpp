/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/WINQ.h>

namespace WCDB {

const ResultColumn ResultColumn::All(lang::ResultColumn::Type::Star);

ResultColumn ResultColumn::AllInTable(const std::string& tableName)
{
    return ResultColumn(tableName); 
}

ResultColumn::ResultColumn(const Expression& expression)
{
    lang::ResultColumn& lang = getMutableLang();
    lang.type = lang::ResultColumn::Type::Expr;
    lang.expr.assign(expression.getLang());
}

ResultColumn::ResultColumn(const lang::ResultColumn::Type& type)
{
    lang::ResultColumn& lang = getMutableLang();
    lang.type = lang::ResultColumn::Type::Star;
}

ResultColumn::ResultColumn(const std::string& tableName)
{
    lang::ResultColumn& lang = getMutableLang();
    lang.type = lang::ResultColumn::Type::Star;
    lang.tableName.assign(tableName);
}

} // namespace WCDB