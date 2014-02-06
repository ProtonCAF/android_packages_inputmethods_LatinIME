/*
 * Copyright (C) 2013, The Android Open Source Project
 *
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

#ifndef LATINIME_DICT_FILE_WRITING_UTILS_H
#define LATINIME_DICT_FILE_WRITING_UTILS_H

#include <cstdio>

#include "defines.h"
#include "suggest/policyimpl/dictionary/header/header_read_write_utils.h"

namespace latinime {

class BufferWithExtendableBuffer;

class DictFileWritingUtils {
 public:
    static const char *const TEMP_FILE_SUFFIX_FOR_WRITING_DICT_FILE;

    static bool createEmptyDictFile(const char *const filePath, const int dictVersion,
            const std::vector<int> localeAsCodePointVector,
            const DictionaryHeaderStructurePolicy::AttributeMap *const attributeMap);

    static bool flushAllHeaderAndBodyToFile(const char *const filePath,
            BufferWithExtendableBuffer *const dictHeader,
            BufferWithExtendableBuffer *const dictBody);

    static bool flushBufferToFileWithSuffix(const char *const basePath, const char *const suffix,
            const BufferWithExtendableBuffer *const buffer);

 private:
    DISALLOW_IMPLICIT_CONSTRUCTORS(DictFileWritingUtils);

    static bool createEmptyV4DictFile(const char *const filePath,
            const std::vector<int> localeAsCodePointVector,
            const DictionaryHeaderStructurePolicy::AttributeMap *const attributeMap);

    static bool flushBufferToFile(const char *const filePath,
            const BufferWithExtendableBuffer *const buffer);

    static bool writeBufferToFile(FILE *const file,
            const BufferWithExtendableBuffer *const buffer);
};
} // namespace latinime
#endif /* LATINIME_DICT_FILE_WRITING_UTILS_H */
