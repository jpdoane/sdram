import vitis 
client = vitis.create_client()
client.set_workspace(path="./workspace")
# platform=client.create_platform_component(name='platform',
#                                                hw_design="./zynq_sdram.xsa",
#                                                cpu = "ps7_cortexa9_0", 
#                                                os = "standalone", 
#                                                domain_name = "standalone_ps7"
#                                                )
# domain = platform.get_domain(name="standalone_ps7")
# status = domain.set_lib(lib_name="lwip220"
#                         , path="D:\Xilinx\Vitis\2024.2\data\embeddedsw\ThirdParty\sw_services\lwip220_v1_1")
# platform.build()

app = client.create_app_component(name ='zynq_sdram_test', 
                                       platform = "./workspace/platform/export/platform/platform.xpfm", 
                                       domain = "standalone_ps7")

app.import_files(from_loc = "../ps_src/")

app.build()
client.close()