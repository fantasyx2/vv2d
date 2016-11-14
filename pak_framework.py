# -*- coding:utf-8 -*-

"""
描述：
Created on 2016/11/14
@author: Line
"""

import os
import shutil
import zipfile
import sys

# framework源码所在的目录


FRAMEWORK_ROOT = './framework'

# QUICK_COCOS2DX_ROOT = "D:/QuickCocos2DX"  引擎的根目录
QUICK_COCOS2DX_ROOT = ""


def copy_file_to_tmp_dir(root, prefix_path, tmp_dir):
	files_list = []
	# print "==========%s: %s ============" % (root, prefix_path)
	for f in os.listdir(root):
		next_root = os.path.join(root, f)
		if os.path.isdir(next_root):
			if prefix_path:
				next_prefix_path = "%s.%s" % (prefix_path, f)
			else:
				next_prefix_path = f
			copy_file_to_tmp_dir(next_root, next_prefix_path, tmp_dir)
		else:
			f_name = f
			if f.endswith(".lua"):
				pos = f.rfind(".")
				f_name = f[0:pos]

			if prefix_path:
				new_filename = os.path.join(tmp_dir, "%s.%s" % (prefix_path, f_name))
			else:
				new_filename = os.path.join(tmp_dir, f_name)
			print("copy %s => %s" % (next_root, new_filename))
			shutil.copy(next_root, new_filename)

def zip_file_dir(path, outfile):
	compression = zipfile.ZIP_DEFLATED
	# start = path.rfind(os.sep) + 1
	start = len(path) + 1
	z = zipfile.ZipFile(outfile, mode="w", compression=compression)
	try:
		for dirpath, dirs, files in os.walk(path):
			for file in files:
				z_path = os.path.join(dirpath, file)
				z.write(z_path, z_path[start:])
		z.close()
	except:
		if z:
			z.close()


def pak_framework_src_to_zip():
	global QUICK_COCOS2DX_ROOT

	if not QUICK_COCOS2DX_ROOT:
		# 没有设置获取环境变量
		QUICK_COCOS2DX_ROOT = os.environ.get('QUICK_COCOS2DX_ROOT')

	print("QUICK_COCOS2DX_ROOT=%s" % (QUICK_COCOS2DX_ROOT,))
	if not QUICK_COCOS2DX_ROOT:
		print("QUICK_COCOS2DX_ROOT is empty....")
		return

	FRAMEWORK_ROOT_ABS_PATH = os.path.join(QUICK_COCOS2DX_ROOT, "framework")
	print("framework root is [%s]" % (FRAMEWORK_ROOT_ABS_PATH,))

	# 创建临时文件夹
	tmp_framework_tmp_dir = "./framework_tmp/"
	tmp_framework_tmp_dir = os.path.abspath(tmp_framework_tmp_dir)
	if not os.path.exists(tmp_framework_tmp_dir):
		os.mkdir(tmp_framework_tmp_dir)
		print("create tmp dir:%s" % (tmp_framework_tmp_dir,))

	print("start copy all .lua to dir:%s" % (tmp_framework_tmp_dir,))
	# 把所有lua文件copy到临时文件下
	copy_file_to_tmp_dir(FRAMEWORK_ROOT_ABS_PATH, "", tmp_framework_tmp_dir)
	print("end copy file")

	print("start zip file")
	zip_out_filename = 'framework_precompiled.zip'  # 压缩后的文件名
	zip_out_filename = os.path.abspath(zip_out_filename)
	zip_file_dir(tmp_framework_tmp_dir, zip_out_filename)
	print("end zip file => %s" % (zip_out_filename,))

	framework_root_lib_abs_path = os.path.join(QUICK_COCOS2DX_ROOT, "lib/framework_precompiled")
	shutil.copy(zip_out_filename, framework_root_lib_abs_path)
	print("copy  %s => %s" % (zip_out_filename, framework_root_lib_abs_path))

	# 删除临时文件
	shutil.rmtree(tmp_framework_tmp_dir)
	# 删除framework_precompiled.zip
	print("del %s" % (zip_out_filename))
	pass


pak_framework_src_to_zip()
