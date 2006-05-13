<Form title="Ingresar paciente" >
	<HBox>
		<Image filename="logo.svg" width="100" height="100" />
		<VBox>
			<Label text="&lt;H1&gt;Ingresar pacientes&lt;/h1&gt;" />
			<Input type="date" />
		</VBox>
	</HBox>
	<VGroupBox title="Informacion personal" >
		<VBox>
			<Input label="Nombres" dbfield="user:login" />
			<Input label="Apellidos" dbfield="user:password" />
		</VBox>
		<HBox>
			<Input type="options" label="Sexo" orientation="0" >
				<RadioButton label="Masculino" id="0" />
				<RadioButton label="Femenino" id="1" />
			</Input>
			<Input type="options" label="Estado civil" orientation="0" >
				<RadioButton label="Soltero" id="0" />
				<RadioButton label="Casado" id="1" />
				<RadioButton label="Viudo" id="2" />
				<RadioButton label="Union libre" id="3" />
			</Input>
			<Input type="options" label="Documento de identidad" orientation="0">
				<RadioButton label="Tarjeta de identidad" id="0" />
				<RadioButton label="Cedula de ciudadania" id="1" />
				<RadioButton label="Cedula extrajera" id="2" />
				<RadioButton label="Pasaporte" id="3" />
				<Input label="No." />
			</Input>
		</HBox>
		<HBox>
			<Input label="Direccion de residencia" />
			<Input label="Municipio" />
		</HBox>
		<HBox>
			<Input label="Telefono de residencia"  />
			<Input label="Movil" />
			<Input label="E-Mail" />
		</HBox>
		<HBox>
			<Input label="Ocupacion" />
			<Input label="Telefono oficina" />
		</HBox>
	</VGroupBox>
	<VGroupBox title="Referencias personales" >
		<HBox>
			<Input label="Persona responsable" />
			<Input label="Parentesco" />
			<Input label="telefono" />
			<Input label="ocupacion" />
		</HBox>
		<HBox>
			<Input label="Persona de referencia" />
			<Input label="Parentesco" />
			<Input label="telefono" />
			<Input label="ocupacion" />
		</HBox>
	</VGroupBox>
</Form>

