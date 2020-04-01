let environment =
  Sihl.Core.Config.Environment.make(
    ~development=[
      ("BASE_URL", "http://localhost:3000"),
      ("EMAIL_SENDER", "josef@oxidizing.io"),
      ("DATABASE_URL", "mysql://root:password@localhost:3306/dev"),
      ("EMAIL_BACKEND", "console"),
    ],
    ~test=[
      ("BASE_URL", "http://localhost:3000"),
      ("EMAIL_SENDER", "josef@oxidizing.io"),
      ("DATABASE_URL", "mysql://root:password@localhost:3306/dev"),
      ("EMAIL_BACKEND", "memory"),
    ],
    ~production=[
      ("EMAIL_BACKEND", "smtp"),
      ("EMAIL_SENDER", "josef@oxidizing.io"),
      ("BASE_URL", "https://sihl-example-issues.oxidizing.io"),
      ("SMTP_SECURE", "false"),
      ("SMTP_HOST", "smtp.ethereal.email"),
      ("SMTP_PORT", "587"),
      ("SMTP_AUTH_USERNAME", "rubie.frami5@ethereal.email"),
      ("SMTP_AUTH_PASSWORD", "DNKj6nyxH1ryS5RAKW"),
    ],
  );

let adminUiPages = [
  Sihl.Users.AdminUi.Page.make(
    ~path="/admin/issues/issues/",
    ~label="Issues",
  ),
  Sihl.Users.AdminUi.Page.make(
    ~path="/admin/issues/boards/",
    ~label="Boards",
  ),
];

let project =
  Sihl.App.Main.Project.make(
    ~environment,
    [Sihl.Users.App.app(adminUiPages), App.app()],
  );
