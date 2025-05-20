	public static void Dispatch_Login() throws Exception {
		// Initiating the driver based on app
		BaseTestCommon.setDriver("optix");
		System.out.println(" driver opened !!");

		try {
			stepwiseExecution("Enter User ID", "Optix_Dispatch_App_Xpaths", "sso_username", "Common_App_Functions", "enterText", Canvas_App_Functions.readconfigPropertyfromFile("optix", "UserID"));

			Thread.sleep(2000);
		//	stepwiseExecution("Enter Password", "Optix_Dispatch_App_Xpaths", "sso_pass", "Common_App_Functions", "enterText", Common_App_Functions.stringdecoder(Canvas_App_Functions.readconfigPropertyfromFile("optix", "Password")));
			stepwiseExecution("Enter Password", "Optix_Dispatch_App_Xpaths", "sso_pass", "Common_App_Functions", "enterText", Canvas_App_Functions.readconfigPropertyfromFile("optix", "Password"));

			Thread.sleep(2000);
			stepwiseExecution("Click Sign In", "Optix_Dispatch_App_Xpaths", "sso_signIn", "Common_App_Functions", "click", "");
			
			stepwiseExecution("Click On Agree", "Optix_Dispatch_App_Xpaths", "Optix_Agreebtn", "Common_App_Functions", "click", "");
			Thread.sleep(5000);
			
//			stepwiseExecution("Enter User ID", "Optix_Dispatch_App_Xpaths", "UserName", "Common_App_Functions", "enterText", Canvas_App_Functions.readconfigPropertyfromFile("optix", "UserID"));
//
//			Thread.sleep(2000);
//			stepwiseExecution("Enter Password", "Optix_Dispatch_App_Xpaths", "Password", "Common_App_Functions", "enterText", Common_App_Functions.stringdecoder(Canvas_App_Functions.readconfigPropertyfromFile("optix", "Password")));
//	
//			Thread.sleep(2000);
//			stepwiseExecution("Click Sign In", "Optix_Dispatch_App_Xpaths", "LogIn", "Common_App_Functions", "click", "");
			
			//stepwiseExecution("Click On Agree", "Optix_Dispatch_App_Xpaths", "Optix_Agreebtn", "Common_App_Functions", "click", "");
			Thread.sleep(5000);

						
		}
		catch(Exception e) {
			System.out.println("Exception in Dispatch_Login: " + e.getMessage());
			Assert.fail("Exception in Dispatch_Login: " + e.getMessage());
		}
	}
