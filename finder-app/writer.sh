#!/bin/sh

writefile=$1
writestr=$2

# 檢查參數
if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "錯誤：請提供完整檔案路徑和寫入字串。"
    exit 1
fi

# 取得資料夾路徑
dirpath=$(dirname "$writefile")

# 如果資料夾不存在就建立它 (包含父目錄)
mkdir -p "$dirpath"

# 建立檔案並寫入文字 (會覆蓋現有內容)
echo "$writestr" > "$writefile"

# 檢查檔案是否成功建立
if [ $? -ne 0 ]; then
    echo "錯誤：無法建立檔案 $writefile"
    exit 1
fi