from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField, TextAreaField
from wtforms.validators import ValidationError, DataRequired, Email, EqualTo, Length

from app.models import NetUser

#######################
# AUTH
#######################
class LoginForm(FlaskForm):
    email = StringField('Email', validators=[DataRequired()], render_kw={"placeholder": "Email"})
    password = PasswordField('Password', validators=[DataRequired()], render_kw={"placeholder": "Password"})
    remember_me = BooleanField('Remember Me')
    submit = SubmitField('Sign In')

class RegistrationForm(FlaskForm):
    username = StringField('UserName', validators=[DataRequired()])
    email = StringField('Email', validators=[DataRequired(), Email()])
    password1 = PasswordField('Password', validators=[DataRequired()])
    password2 = PasswordField(
        'Repeat Password', validators=[DataRequired(), EqualTo('password1')])
    submit = SubmitField('Register')

    def validate_username(self, username):
        user = NetUser.query.filter_by(username=username.data).first()
        if user is not None:
            raise ValidationError('This username is already registered.')

    def validate_email(self, email):
        user = NetUser.query.filter_by(email=email.data).first()
        if user is not None:
            raise ValidationError('This email is already registered.')
   
class EditProfileForm(FlaskForm):
    first_name = TextAreaField('First Name', validators=[Length(min=0, max=140)])
    last_name = TextAreaField('Last Name', validators=[Length(min=0, max=140)])
    new_email = StringField('Email', validators=[DataRequired(), Email()])
    submit = SubmitField('Update')


class ResetPasswordRequestForm(FlaskForm):
    email = StringField('Email', validators=[DataRequired(), Email()])
    submit = SubmitField('Send My Password Reset Link')


class ResetPasswordForm(FlaskForm):
    password1 = PasswordField('Password', validators=[DataRequired()])
    password2 = PasswordField(
        'Repeat Password', validators=[DataRequired(), EqualTo('password1')])
    submit = SubmitField('Request Password Reset')
